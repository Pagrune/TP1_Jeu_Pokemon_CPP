#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include "Player.h"
#include <string>

using namespace std;

class TrainerCard : public Card{
    private :
        string _trainerEffect;
    public : 
        // Constructor
        TrainerCard();
        TrainerCard(const string& name, const string& effect);

        string getTrainerEffect() const;

        void actionEffect(Player& player);


        void displayInfo() override;

};


#endif