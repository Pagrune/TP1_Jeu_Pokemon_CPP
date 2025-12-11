#include "EnergyCard.h"
#include <iostream>
using namespace std;

EnergyCard::EnergyCard(const string& _name){
    cardName = _name;
    energyType = "Energy";
}

string EnergyCard::getEnergyType() const{
    return energyType;
}

void EnergyCard::displayInfo(){
    cout << "Card Name: " << getCardName() << endl;
    cout << "Type:" << getEnergyType() << endl;
}