#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include "EnergyCard.h"
#include <string>
#include <vector>

using namespace std;

class PokemonCard : public Card{
    private :
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int hp;
        int maxHP;
        vector<EnergyCard*> attachedEnergies;

        // vector de tuple (coût en énergie, coût en énergie actuel, description de l'attaque, dégâts)
        vector<tuple<int, string, int>> attacks;
    public:
        //constructor
        PokemonCard();
        PokemonCard(const string& _name, const string& _pokemonType, const string& _familyName, const int& _evolutionLevel, const int& _hp, const vector<tuple<int, string, int>>& _attacks);

        // getters
        string getPokemonType() const;
        string getFamilyName() const;
        int getEvolutionLevel() const;
        int getHP() const;
        vector<tuple<int, string, int>> getAttacks() const;
        int getEnergyCount() const;
        int getMaxHP() const;


        // setter
        void setHP(int newHP);

        bool canUseAttack(int attackIndex) const;

        int getAttackEnergyCost(int attackIndex) const;
        int getAttackDamage(int attackIndex) const;
        void consumeEnergy(int amount);
        void takeDamage(int damage);

        void addEnergy(EnergyCard* energy);


        void displayInfo() override;

};

#endif