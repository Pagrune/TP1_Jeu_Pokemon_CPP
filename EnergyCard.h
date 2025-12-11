#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>

using namespace std;

class EnergyCard : public Card{
    private :
        string _energyType;
    public : 
        // Constructor
        EnergyCard();
        EnergyCard(const string& name);

        string getEnergyType() const;


        void displayInfo() override;

};


#endif