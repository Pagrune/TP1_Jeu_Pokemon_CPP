#include "PokemonCard.h"
#include <iostream>
using namespace std;

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

// setters
void PokemonCard::setPokemonType(const string& type) {
    pokemonType = type;
}

void PokemonCard::setFamilyName(const string& family) {
    familyName = family;
}

void PokemonCard::setEvolutionLevel(int level) {
    evolutionLevel = level;
}

void PokemonCard::setMaxHP(int maxHp) {
    maxHP = maxHp;
}

void PokemonCard::setHP(int hpValue) {
    hp = hpValue;
}

void PokemonCard::addAttack(int energyCost, const string& description, int damage) {
    attacks.emplace_back(energyCost, 0, description, damage);
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
