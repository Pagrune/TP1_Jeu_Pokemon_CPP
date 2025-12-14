#include "Player.h"
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

void Player::attachEnergyCard(PokemonCard* pokemonCard, Card* energyCard){


}
