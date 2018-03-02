/* 
 * File:   Coin.cpp
 * Author: John Donahue
 * 
 * Created on February 26, 2018, 11:29 AM
 * @version 02/26/2018
 */

#include "Coin.h"

Coin::Coin() {
}

Coin::Coin(int newVal, string newName)
{
    value = newVal;
    name = newName;
}

Coin::Coin(const Coin& orig) {
}

Coin::~Coin() { // nothing to destroy in this class
}

int Coin::getValue()
{
    return value;
}

string Coin::getName()
{
    return name;
}