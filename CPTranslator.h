/* 
 * File:   CPTranslator.h
 * Author: John Donahue
 *
 * Created on March 1, 2018, 11:11 AM
 * @version 03/02/2018
 */

#ifndef CPTRANSLATOR_H
#define	CPTRANSLATOR_H
#include <vector>
#include "Coin.h"
#include <sstream> // <string> is included

#include <iostream>

class CPTranslator {
public:
    CPTranslator();
    CPTranslator(const CPTranslator& orig);
    virtual ~CPTranslator();
    string toStringAllInfo(vector<Coin *> coins, vector<int> nums);
    string translateCoinPath(vector<Coin *> coins, vector<int> nums, int val);
    string translateCoinTypes(vector<Coin *> coinTypes);
    
    
private:

};

#endif	/* CPTRANSLATOR_H */

