#include "Player.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include <iostream>

#include<string>
#include<vector>


using namespace std;

Player::Player(){};

Player::Player(const string& playerName): _playerName(playerName){
}

string Player::getPlayerName() const{
    return _playerName;
}

void Player::addCardToBench(Card* card){
    _benchCard.push_back(card);
}

vector<Card*> Player::getBenchCards() const{
    return _benchCard;
}

void Player::attachEnergyCard(PokemonCard* pokemonCard, Card* energyCard)
{
    if (!pokemonCard || !energyCard) {
        cout << "Erreur : pointeur nul." << endl;
        return;
    }

    // Vérifier que la carte énergie est bien sur le bench
    auto it = find(_benchCard.begin(), _benchCard.end(), energyCard);
    if (it == _benchCard.end()) {
        cout << "Erreur : la carte énergie n'est pas sur le bench." << endl;
        return;
    }

    // Vérifier que c'est bien une carte énergie
    EnergyCard* energy = dynamic_cast<EnergyCard*>(energyCard);
    if (!energy) {
        cout << "Erreur : carte non-énergie." << endl;
        return;
    }

    // Retirer l'énergie du bench
    _benchCard.erase(it);

    // Attacher l'énergie au Pokémon
    pokemonCard->addEnergy(energy);

    cout << getPlayerName()
         << " is attaching Energy Card of type : "
         << energy->getEnergyType()
         << " to the Pokemon "
         << pokemonCard->getCardName()
         << endl;
}



void Player::activatePokemonCard(PokemonCard* pokemonCard){
    if (!pokemonCard) return;

    // Chercher la carte dans le bench
    auto it = find(_benchCard.begin(), _benchCard.end(), pokemonCard);

    if (it == _benchCard.end()) {
        cout << "Erreur : le Pokémon n'est pas sur le bench." << endl;
        return;
    }

    // Retirer du bench
    _benchCard.erase(it);

    // Ajouter aux cartes actives
    _actionCard.push_back(pokemonCard);

    cout << getPlayerName()
         << " is activating the Pokemon Card : "
         << pokemonCard->getCardName() << endl;
}


void Player::useTrainer(Card* trainerCard){
    cout << "Utilisation de la carte d'entraîneur : " << trainerCard->getCardName() << endl;
}


void Player::attack(PokemonCard* attacker,
                    int attackIndex,
                    Player& opponent,
                    PokemonCard* defender)
{
    if (!attacker || !defender) {
        cout << "Erreur : Pokémon invalide." << endl;
        return;
    }

    // Vérifier si l'attaque est possible
    if (!attacker->canUseAttack(attackIndex)) {
        cout << attacker->getCardName()
             << " does not have enough energy to use this attack."
             << endl;
        return;
    }

    int damage = attacker->getAttackDamage(attackIndex);
    int energyCost = attacker->getAttackEnergyCost(attackIndex);

    cout << getPlayerName()
         << " attacking "
         << opponent.getPlayerName()
         << "'s Pokemon " << defender->getCardName()
         << " with the Pokemon " << attacker->getCardName()
         << " with its attacks " << get<1>(attacker->getAttacks()[attackIndex]) <<endl         
         << "Reducing " << damage << " from " << defender->getCardName()
         << "'s Pokemon's HP."
         << endl;

    // Infliger les dégâts
    defender->takeDamage(damage);

    // Consommer l'énergie
    attacker->consumeEnergy(energyCost);

    // Vérifier KO
    if (defender->getHP() == 0) {
        cout << defender->getCardName()
             << " is knocked out!" << endl;
    }
    else{
        cout << defender->getCardName()
             << " is still alive" << endl;
    }
}


void Player::displayAction(){
    cout << "Action Cards of " << getPlayerName() << " :" << endl;
    for (const auto& card : _actionCard) {
        card->displayInfo();
        cout << "------------------------" << endl;
    }
}

void Player::displayBench(){
    cout << "Bench Cards for " << getPlayerName() << " :" << endl;
    for (const auto& card : _benchCard) {
        card->displayInfo();
        cout << "------------------------" << endl;
    }
}
