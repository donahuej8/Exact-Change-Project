/* 
 * File:   ChangeMachine.cpp
 * Author: John Donahue
 * 
 * Created on March 1, 2018, 12:00 PM
 * @version 03/01/2018
 */

#include "ChangeMachine.h"

ChangeMachine::ChangeMachine() {
    processor = new ChangeProcessor();
    translator = new CPTranslator();
}

ChangeMachine::ChangeMachine(vector<Coin*> typesOfCoins) {
    processor = new ChangeProcessor(typesOfCoins);
    translator = new CPTranslator();
}

ChangeMachine::ChangeMachine(const ChangeMachine& orig) {
}

ChangeMachine::~ChangeMachine() {
    // need to destroy translator and processor
    delete translator;
    delete processor;
}

string ChangeMachine::getAllInfo()
{
    return translator->toStringAllInfo(processor->getCoinPtrs(), processor->getNumsRequired());
}

string ChangeMachine::getPath(int val)
{
    if (val < 0)
    {
        return "INVALID";
    }
    processor->calculateCoins(val); // if not needed, nothing happens anyway
    return translator->translateCoinPath(processor->getCoinPtrs(), processor->getNumsRequired(), val);
    
}

string ChangeMachine::getTypes()
{
    return translator->translateCoinTypes(processor->getCoinTypes());
}