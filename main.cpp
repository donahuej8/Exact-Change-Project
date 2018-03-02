/* 
 * File:   main.cpp
 * Author: John Donahue
 *
 * Created on February 26, 2018, 11:29 AM
 * @version 03/02/2018
 */

#include <cstdlib>
#include <iostream>
#include "ChangeMachine.h"

using namespace std;

ChangeMachine *myMachine;
vector<Coin *> coins;

void setDefault2()
{
    Coin *penny = new Coin(1, "Penny");
    Coin *dime = new Coin(10, "Dime");
    Coin *quarter = new Coin(25, "Quarter");
    coins.push_back(penny);
    coins.push_back(dime);
    coins.push_back(quarter);
    myMachine = new ChangeMachine(coins);
}

void setDefault3()
{
    Coin *penny = new Coin(1, "Penny");
    coins.push_back(penny);
    myMachine = new ChangeMachine(coins);
}

/*
 * 
 */
int main(int argc, char** argv) {
    int numCoins = 0;
    bool gettingCoins = true;
    
    cout << "| - Coin Change Processing Project - |" << endl;
    
    cout << "Please choose from the following:" << endl;
    cout << "(1) Default 1: Penny Nickel Dime Quarter" << endl;
    cout << "(2) Default 2: Penny Dime Quarter" << endl;
    cout << "(3) Default 3: Penny" << endl;
    cout << "(4) Custom: Make your own coins!" << endl;
    cout << "Enter your decision here: ";
    int machineType;
    cin >> machineType;
    cout << machineType << endl;
    
    switch (machineType)
    {
        case 1: // Default 1: Penny Nickel Dime Quarter
            myMachine = new ChangeMachine();
            break;
            
        case 2: // Default 2: Penny Dime Quarter
            setDefault2();
            break;
            
        case 3: // Default 3: Penny
            setDefault3();
            break;
            
        case 4: // Custom
            while (gettingCoins == true)
            {
                cout << "How many coins would you like to create? ";
                cin >> numCoins;
                cout << numCoins << endl;
                if (numCoins <= 0)
                {
                    cout << "Invalid number of coins! Please try again." << endl;
                }
                else
                {
                    gettingCoins = false;
                }
            }
            
            cout << "Let's create some currency!" << endl;
            cout << "WARNING: Creation of a coin with a value of 1 cent is highly advised." << endl;
            cout << "Please create coins in least-to-greatest value order." << endl;
            
            for (int i = 0; i < numCoins; i++)
            {
                cout << "Enter value for coin " << (i+1) << ": ";
                int value;
                cin >> value;
                cout << value << endl;
                cout << "Enter name for coin " << (i+1) << ": ";
                string name;
                cin >> name;
                cout << name << endl;
                Coin *newCoin = new Coin(value, name);
                coins.push_back(newCoin);
            }
            
            myMachine = new ChangeMachine(coins);
            break;
            
        default:
            cout << "Invalid Choice!" << endl;
            break;
    }
    cout << "\n" << endl;
    bool working = true;
    while (working == true)
    {
        cout << "Choose from the following..." << endl;
        cout << "(1) Get Exact Change." << endl;
        cout << "(2) Print info on coin types." << endl;
        cout << "(3) Print info on previous calculations." << endl;
        cout << "(4) Exit program.";
        cout << "Enter your decision here: ";
        int decision;
        cin >> decision;
        cout << decision << endl;
        
        switch (decision)
        {
            case 1: // Get Exact Change
                cout << "Enter the change you need (in cents): ";
                int change;
                cin >> change;
                cout << change << endl;
                if (change > 0)
                {
                    cout << myMachine->getPath(change) << endl;
                }
                else
                {
                    cout << "Cannot produce change!" << endl;
                }
                break;
                
            case 2: // Print info on coin types
                cout << myMachine->getTypes() << endl;
                break;
                
            case 3: // Print info on previous calculations
                cout << myMachine->getAllInfo() << endl;
                break;
                
            case 4: // Exit program
                working = false;
                cout << "Ending program..." << endl;
                break;
                
            default:
                cout << "Invalid Decision!" << endl;
                break;
        }
    }
    cout << "All done!" << endl;
    
    return 0;
}

