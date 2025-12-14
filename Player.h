#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
#include <algorithm>

using namespace std;

class Player{
    private : 
        string _playerName;
        vector<Card*> _benchCard;
        vector<PokemonCard*> _actionCard;
    
    public:
        // constructor
        Player();
        Player(const string& playerName);

        // getter
        string getPlayerName() const;

        // get bench cards
        vector<Card*> getBenchCards() const;

        vector<PokemonCard*> getActionCards() const;


        // addCardtoBench
        void addCardToBench(Card* card);

        // attachEnergyCard
        void attachEnergyCard(PokemonCard* pokemonCard, Card* energyCard);

        // activatePokemonCard
        void activatePokemonCard(PokemonCard* pokemonCard);

        // useTrainer
        void useTrainer(Card* trainerCard);

        // attack
        void attack(PokemonCard* attacker, int attackIndex, Player& opponent, PokemonCard* defender);

        //displayAction
        void displayAction();

        // displayBench
        void displayBench();

};


#endif