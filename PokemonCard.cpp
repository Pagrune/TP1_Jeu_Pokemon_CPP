#include "PokemonCard.h"
#include <iostream>
#include <vector>
using namespace std;

// constructor
PokemonCard::PokemonCard() : Card(), pokemonType(""), familyName(""), evolutionLevel(0), hp(0) {
}

PokemonCard::PokemonCard(const string& _name,
                         const string& _pokemonType,
                         const string& _familyName,
                         const int& _evolutionLevel,
                         const int& _hp,
                         const vector<tuple<int, string, int>>& _attacks)
    : Card(_name),
      pokemonType(_pokemonType),
      familyName(_familyName),
      evolutionLevel(_evolutionLevel),
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

bool PokemonCard::canUseAttack(int attackIndex) const {
    if (attackIndex < 0 || attackIndex >= attacks.size())
        return false;

    int energyCost = get<0>(attacks[attackIndex]);
    return getEnergyCount() >= energyCost;
}

int PokemonCard::getAttackEnergyCost(int attackIndex) const {
    return get<0>(attacks[attackIndex]);
}

int PokemonCard::getAttackDamage(int attackIndex) const {
    return get<2>(attacks[attackIndex]);
}

void PokemonCard::consumeEnergy(int amount) {
    for (int i = 0; i < amount && !attachedEnergies.empty(); i++) {
        attachedEnergies.pop_back();
    }
}

void PokemonCard::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}




void PokemonCard::displayInfo() {
    cout << "Pokemon Card - ";
    cout << "Name: " << getCardName() << ", ";
    cout << "Type: " << pokemonType << ", ";
    cout << "Evolution Level: " << evolutionLevel << "of the family " << familyName << ", ";
    cout << "HP: " << hp << ", " << endl;

    cout << "Attacks:" << endl;
    for (const auto& attack : attacks) {
        cout << "Attack #" << (&attack - &attacks[0]) << " :" << endl;
        cout << "Attack Cost: " << get<0>(attack) << endl
             << "Attack Current Energy: " << getEnergyCount() << endl
             << "Attack Description: " << get<1>(attack) << endl
             << "Attack Damage: " << get<2>(attack) << endl;
    }
}