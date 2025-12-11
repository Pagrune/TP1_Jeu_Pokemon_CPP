#include "TrainerCard.h"
#include "Card.h"
#include <iostream>
using namespace std;

TrainerCard::TrainerCard(){};

TrainerCard::TrainerCard(const string& name) : Card(name), _trainerEffect("Heal all your action pokemon"){
}

string TrainerCard::getTrainerEffect() const{
    return _trainerEffect;
}

void TrainerCard::displayInfo(){
    cout << "Card Name: " << getCardName() << endl;
    cout << "Effet:" << getTrainerEffect() << endl;
}