#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card{
    protected:
        string cardName;
       
    public:
        // getter for cardName
        string getCardName() const {
            return cardName;
        }

        void setCardName(const string& name) {
            cardName = name;
        }

        virtual void displayInfo() = 0;
};


#endif