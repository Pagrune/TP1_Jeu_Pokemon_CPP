#include "Player.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include <iostream>

#include<string>
#include<vector>


using namespace std;

Player::Player(){};

Player::Player(const string& playerName): _playerName(playerName){
}

string Player::getPlayerName() const{
    return _playerName;
}

void Player::addCardToBench(Card* card){
    _benchCard.push_back(card);
}

void Player::attachEnergyCard(PokemonCard* pokemonCard, Card* energyCard)
{
    if (!pokemonCard || !energyCard) {
        cout << "Erreur : pointeur nul." << endl;
        return;
    }

    EnergyCard* energy = dynamic_cast<EnergyCard*>(energyCard);
    if (!energy) {
        cout << "Erreur : carte non-énergie." << endl;
        return;
    }

    pokemonCard->addEnergy(energy);

    cout << getPlayerName() 
        << " is attaching Energy Card of type : " << energy->getEnergyType()
         << " to the Pokemon " << pokemonCard->getCardName() << endl;
}


void Player::activatePokemonCard(PokemonCard* pokemonCard){
    _actionCard.push_back(pokemonCard);
    cout << getPlayerName() 
        << " is activating the Pokemon Card : " << pokemonCard->getCardName() << endl;
}

void Player::useTrainer(Card* trainerCard){
    cout << "Utilisation de la carte d'entraîneur : " << trainerCard->getCardName() << endl;
}

