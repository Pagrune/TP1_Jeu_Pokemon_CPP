#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include <string>

using namespace std;

class TrainerCard : public Card{
    private :
        string _trainerEffect;
    public : 
        // Constructor
        TrainerCard();
        TrainerCard(const string& name);

        string getTrainerEffect() const;


        void displayInfo() override;

};


#endif