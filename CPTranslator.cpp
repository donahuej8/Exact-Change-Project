/* 
 * File:   CPTranslator.cpp
 * Author: John Donahue
 * 
 * The ChangeProcessorTranslator is used to convert the data gathered from the
 *   ChangeProcessor into readable and well-formatted strings. These strings are
 *   seen and interpreted by the user so that they can see what they have done.
 * 
 * Created on March 1, 2018, 11:11 AM
 * @version 03/02/2018
 */

#include "CPTranslator.h"

CPTranslator::CPTranslator() {
}

CPTranslator::CPTranslator(const CPTranslator& orig) {
}

CPTranslator::~CPTranslator() { // nothing to destroy in this class
}

string CPTranslator::toStringAllInfo(vector<Coin*> coins, vector<int> nums)
{
    string result = "";
    /*
     * [index] numrequired -> coin_to_return = coin_value
     * ex:
     *  0 cents -> 0 coins: NONE = 0
     *  1 cents -> 1 coins: Penny = 1
     *  15 cents -> 2 coins: Nickel = 5
     */
    for (int i = 0; i < coins.size(); i++)
    {
        string name = coins[i]->getName();
        stringstream value;
        stringstream req;
        stringstream curr;
        value << coins[i]->getValue();
        req << nums[i];
        curr << i;
        
        result += curr.str();
        result += " cents -> ";
        result += req.str();
        result += " coins: ";
        result += name;
        result += " = ";
        result += value.str();
        result += "\n";
    }
    return result;
}

string CPTranslator::translateCoinPath(vector<Coin *> coins, vector<int> nums, int val)
{
    /*
     * "For *val* cents, you will need..." + info
     * info = x quarter's, y nickel's, z penny's
     */
    stringstream value;
    stringstream totalCoins;
    value << val;
    totalCoins << nums[val];
    
    string result = "For ";
    result += value.str();
    result += " cents, you will need ";
    result += totalCoins.str();
    result += " coins...\n";
    while (val > 0)
    {
        string name = coins[val]->getName();
        result += name;
        result += "  ";
        val -= coins[val]->getValue();
    }
    return result;
}

string CPTranslator::translateCoinTypes(vector<Coin*> coinTypes)
{
    string result = "";
    
    /*
     * Coin x: *Name* = *Value*
     */
    for (int i = 0; i < coinTypes.size(); i++)
    {
        string name = coinTypes[i]->getName();
        stringstream curr;
        stringstream value;
        curr << (i+1);
        value << coinTypes[i]->getValue();
        result += "Coin ";
        result += curr.str();
        result += ": ";
        result += name;
        result += " = ";
        result += value.str();
        result += "\n";
    }
    return result;
}