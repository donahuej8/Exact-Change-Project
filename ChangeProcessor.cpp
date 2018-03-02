/* 
 * File:   ChangeProcessor.cpp
 * Author: John Donahue
 * 
 * Created on February 26, 2018, 11:35 AM
 * @version 03/01/2018
 */

#include "ChangeProcessor.h"

/* NOTE: This processor assumes that the list of coins is in increasing order */

/**
 * Default processor with 4 basic coin types
 */
ChangeProcessor::ChangeProcessor() {
    Coin *penny = new Coin(1, "Penny");
    Coin *nickel = new Coin(5, "Nickel");
    Coin *dime = new Coin(10, "Dime");
    Coin *quarter = new Coin(25, "Quarter");
    Coin *noCoin = new Coin(0, "NONE"); // not to be included in coinTypes
    coinTypes.push_back(penny);
    coinTypes.push_back(nickel);
    coinTypes.push_back(dime);
    coinTypes.push_back(quarter);
    numsRequired.push_back(0);
    coinptrs.push_back(noCoin);
}

/**
 * Processor with specified coin types (as many as the user chooses)
 * @param typesOfCoins
 * @param numTypes
 */
ChangeProcessor::ChangeProcessor(vector<Coin*> typesOfCoins)
{
    Coin *noCoin = new Coin(0, "NONE"); // not to be included in coinTypes
    numsRequired.push_back(0);
    coinptrs.push_back(noCoin);
    coinTypes = typesOfCoins;
}

ChangeProcessor::ChangeProcessor(const ChangeProcessor& orig) {
}

ChangeProcessor::~ChangeProcessor() { // nothing to destroy in this class
}

vector<Coin *> ChangeProcessor::getCoinPtrs()
{
    return coinptrs;
}

vector<int> ChangeProcessor::getNumsRequired()
{
    return numsRequired;
}

vector<Coin *> ChangeProcessor::getCoinTypes()
{
    return coinTypes;
}

/**
 * User inputs the value which is equal to the index.
 * @param val
 * @return 
 */
void ChangeProcessor::calculateCoins(int val)
{
    if (val > coinptrs.size()) // size = next slot in list
    {
        //calculate previous coin (recursive)
        calculateCoins(val - 1);
    } // recursion stops at the size (last one to calculate)
    if (val < coinptrs.size())
    {
        return; // prevent re-calculations
    }
    
    /* Calculate Current Coin */
    Coin *minChoice = coinTypes[0];
    int minNum = numsRequired[val - minChoice->getValue()]; // go back by lowest coin value
    // Test smallest coin first
    if (val - minNum == 0) // see if equal to a coin value
    {
        // set values for vectors
        coinptrs.insert(coinptrs.begin() + val, minChoice);
        numsRequired.insert(numsRequired.begin() + val, 1);
        return;
    }
    if (val - minNum < 0) // see if valid
    {
        //return coinptrs[0]; // INVALID
        return;
    }
    // Test all other coins
    int i = 1; // already tested the first coin
    bool calculating = true;
    while (i < coinTypes.size() && calculating == true)
    {
        if (val - coinTypes[i]->getValue() == 0) // see if equal to a coin value
        {
            minChoice = coinTypes[i];
            // set values for vectors
            coinptrs.insert(coinptrs.begin() + val, minChoice);
            numsRequired.insert(numsRequired.begin() + val, 1);
            calculating = false; //IS THIS NEEDED?
            //return coinTypes[i]; // break out early
            return;
        }
        if (val - coinTypes[i]->getValue() < 0) // see if valid
        {
            calculating = false; // don't do any more calculation! (errors will occur otherwise)
        }
        else if (numsRequired[val - coinTypes[i]->getValue()] < minNum)
        {
            minChoice = coinTypes[i];
            minNum = numsRequired[val - minChoice->getValue()]; // go back as many spaces as the other coin is worth
        }
        i++;
    }
    // set values for vectors
    coinptrs.insert(coinptrs.begin() + val, minChoice);
    numsRequired.insert(numsRequired.begin() + val, minNum + 1); // add one because you are adding a coin
    //return minChoice;
}