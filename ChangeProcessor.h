/* 
 * File:   ChangeProcessor.h
 * Author: John Donahue
 *
 * Created on February 26, 2018, 11:35 AM
 * @version 03/01/2018
 */

#ifndef CHANGEPROCESSOR_H
#define	CHANGEPROCESSOR_H
#include <vector>
#include "Coin.h"

class ChangeProcessor {
public:
    ChangeProcessor(); // default
    ChangeProcessor(vector<Coin*> typesOfCoins); // specific
    ChangeProcessor(const ChangeProcessor& orig);
    virtual ~ChangeProcessor();
    vector<Coin *> getCoinPtrs();
    vector<int> getNumsRequired();
    vector<Coin *> getCoinTypes();
    void calculateCoins(int val);
    
private:
    vector<Coin *> coinptrs;
    vector<int> numsRequired;
    vector<Coin *> coinTypes;
};

#endif	/* CHANGEPROCESSOR_H */

