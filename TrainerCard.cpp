#include "TrainerCard.h"
#include "Card.h"
#include <iostream>
using namespace std;

TrainerCard::TrainerCard(){};

TrainerCard::TrainerCard(const string& name, const string& effect) : Card(name), _trainerEffect(effect){
}

string TrainerCard::getTrainerEffect() const{
    return _trainerEffect;
}

void TrainerCard::displayInfo(){
    cout << "Trainer Card - Name: " << getCardName() << ", ";
    cout << "Effect:" << getTrainerEffect() << endl;
}