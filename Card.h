#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card{
    protected:
        string _cardName;
       
    public:
        // Constructor
        Card(){};
        Card(const string& cardName) : _cardName(cardName) {}

        // getter for cardName
        string getCardName() const {
            return _cardName;
        }


        virtual void displayInfo() = 0;
};


#endif