#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"

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

};


#endif