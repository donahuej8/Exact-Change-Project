/* 
 * File:   ChangeMachine.h
 * Author: John Donahue
 *
 * Created on March 1, 2018, 12:00 PM
 * @version 03/01/2018
 */

#ifndef CHANGEMACHINE_H
#define	CHANGEMACHINE_H
#include "ChangeProcessor.h"
#include "CPTranslator.h"

class ChangeMachine {
public:
    ChangeMachine(); // default processor
    ChangeMachine(vector<Coin*> typesOfCoins); // specified processor
    ChangeMachine(const ChangeMachine& orig);
    virtual ~ChangeMachine();
    string getAllInfo();
    string getPath(int val);
    string getTypes();
    
private:
    ChangeProcessor *processor;
    CPTranslator *translator;

};

#endif	/* CHANGEMACHINE_H */

