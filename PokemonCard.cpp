#include "PokemonCard.h"
#include <iostream>
#include <vector>
using namespace std;

// constructor
PokemonCard::PokemonCard() : Card(), pokemonType(""), familyName(""), evolutionLevel(0), maxHP(0), hp(0) {
}

PokemonCard::PokemonCard(const string& _name,
                         const string& _pokemonType,
                         const string& _familyName,
                         const int& _evolutionLevel,
                         const int& _maxHP,
                         const int& _hp,
                         const vector<tuple<int, string, int>>& _attacks)
    : Card(_name),
      pokemonType(_pokemonType),
      familyName(_familyName),
      evolutionLevel(_evolutionLevel),
      maxHP(_maxHP),
      hp(_hp),
      attacks(_attacks) {
}


// getters
string PokemonCard::getPokemonType() const {
    return pokemonType;
}

string PokemonCard::getFamilyName() const {
    return familyName;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

int PokemonCard::getHP() const {
    return hp;
}

vector<tuple<int, string, int>> PokemonCard::getAttacks() const {
    return attacks;
}

void PokemonCard::addEnergy(EnergyCard* energy) {
    attachedEnergies.push_back(energy);
}

int PokemonCard::getEnergyCount() const {
    return attachedEnergies.size();
}



void PokemonCard::displayInfo() {
    cout << "Pokemon Card - ";
    cout << "Name: " << getCardName() << ", ";
    cout << "Type: " << pokemonType << ", ";
    cout << "Evolution Level: " << evolutionLevel << "of the family " << familyName << ", ";
    cout << "HP: " << maxHP << ", " << endl;

    cout << "Attacks:" << endl;
    for (const auto& attack : attacks) {
        cout << "Attack #" << (&attack - &attacks[0]) << " :" << endl;
        cout << "Attack Cost: " << get<0>(attack) << endl
             << "Attack Current Energy: " << getEnergyCount() << endl
             << "Attack Description: " << get<1>(attack) << endl
             << "Attack Damage: " << get<2>(attack) << endl;
    }
}