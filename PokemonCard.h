#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>

using namespace std;

class PokemonCard : public Card{
    private :
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;

        // vector de tuple (coût en énergie, coût en énergie actuel, description de l'attaque, dégâts)
        vector<tuple<int, int, string, int>> attacks;
    public:
        //constructor
        PokemonCard(const string& _name, const string& _pokemonType, const string& _familyName, const int& _evolutionLevel, const int& _maxHP, const int& _hp);

        // getters
        string getPokemonType() const;
        string getFamilyName() const;
        int getEvolutionLevel() const;
        int getMaxHP() const;
        int getHP() const;
        vector<tuple<int, int, string, int>> getAttacks() const;



        void displayInfo() override;

};

#endif