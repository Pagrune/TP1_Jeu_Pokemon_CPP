#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>

using namespace std;

class EnergyCard : public Card{
    private :
        string energyType;
    public : 
        // Constructor
        EnergyCard(const string& _name);

        string getEnergyType() const;


        void displayInfo() override;

};


#endif