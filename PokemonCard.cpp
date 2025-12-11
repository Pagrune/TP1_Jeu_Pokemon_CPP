#include "PokemonCard.h"
#include <iostream>
#include <vector>
using namespace std;

// constructor
PokemonCard::PokemonCard() : Card(), pokemonType(""), familyName(""), evolutionLevel(0), maxHP(0), hp(0) {
}

PokemonCard::PokemonCard(const string& _name, const string& _pokemonType, const string& _familyName, const int& _evolutionLevel, const int& _maxHP, const int& _hp, const vector<tuple<int, int, string, int>>& _attacks)
    : Card(_name), pokemonType(_pokemonType), familyName(_familyName), evolutionLevel(_evolutionLevel), maxHP(_maxHP), hp(_hp), attacks(_attacks) {
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

vector<tuple<int, int, string, int>> PokemonCard::getAttacks() const {
    return attacks;
}

void PokemonCard::displayInfo() {
    cout << "Card Name: " << getCardName() << endl;
    cout << "Pokemon Type: " << pokemonType << endl;
    cout << "Family Name: " << familyName << endl;
    cout << "Evolution Level: " << evolutionLevel << endl;
    cout << "Max HP: " << maxHP << endl;
    cout << "Current HP: " << hp << endl;
    cout << "Attacks:" << endl;
    for (const auto& attack : attacks) {
        cout << "  Energy Cost: " << get<0>(attack)
             << ", Current Energy: " << get<1>(attack)
             << ", Description: " << get<2>(attack)
             << ", Damage: " << get<3>(attack) << endl;
    }
}
