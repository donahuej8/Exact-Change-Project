/* 
 * File:   Coin.h
 * Author: John Donahue
 *
 * Created on February 26, 2018, 11:29 AM
 * @version 02/26/2018
 */

#ifndef COIN_H
#define	COIN_H
#include <string>

using namespace std;
class Coin {
public:
    Coin();
    Coin(int newVal, string newName);
    Coin(const Coin& orig);
    virtual ~Coin();
    int getValue();
    string getName();
    
private:
    int value;
    string name;

};

#endif	/* COIN_H */

