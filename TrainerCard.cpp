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

void TrainerCard::actionEffect(Player& player) {
    if (_trainerEffect == "Heal all your action pokemon") {
        // Parcours des cartes actives
        for (auto& card : player.getActionCards()) {
            PokemonCard* pokemon = dynamic_cast<PokemonCard*>(card);
            if (pokemon) {
                // Soigner le Pokémon jusqu'au maximum de PV
                pokemon->setHP(pokemon->getMaxHP());
            }
        }
    } else {
        cout << "Trainer effect not implemented: " 
             << _trainerEffect << endl;
    }
}


void TrainerCard::displayInfo(){
    cout << "Trainer Card - Name: " << getCardName() << ", ";
    cout << "Effect:" << getTrainerEffect() << endl;
}