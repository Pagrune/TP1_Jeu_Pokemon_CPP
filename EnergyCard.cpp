#include "EnergyCard.h"
#include "Card.h"
#include <iostream>
using namespace std;

EnergyCard::EnergyCard(){};

EnergyCard::EnergyCard(const string& name) : Card(name), _energyType("Energy"){
}

string EnergyCard::getEnergyType() const{
    return _energyType;
}

void EnergyCard::displayInfo(){
    cout << "Card Name: " << getCardName() << endl;
    cout << "Type:" << getEnergyType() << endl;
}