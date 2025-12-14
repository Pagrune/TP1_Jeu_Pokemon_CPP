#include "Card.h"
#include "EnergyCard.h"
#include "PokemonCard.h"
#include "TrainerCard.h"
#include "Player.h"

#include <string>
#include <vector>

using namespace std;

int main(){
    Player player1("Hadi");

    string nomCarteEnergyElec = "Electric";

    EnergyCard energyElectric= EnergyCard(nomCarteEnergyElec);

    // energy.displayInfo();

    // cout << endl;
    string nomCartePokemon = "Pikachu";
    string typePokemon = "Electrik";
    string famillePokemon = "Pikachu";
    int niveauEvolution = 1;
    int pointsDeVieMax = 100;
    int pointsDeVieActuels = 80;
    vector<tuple<int, int, string, int>> attaques = {
        make_tuple(2, 2, "Éclair", 30),
        make_tuple(3, 2, "Tonnerre", 50)
    };
    PokemonCard pokemonPikachu = PokemonCard(nomCartePokemon, typePokemon, famillePokemon, niveauEvolution, pointsDeVieMax, pointsDeVieActuels, attaques);
    
    player1.addCardToBench(&energyElectric);
    player1.addCardToBench(&energyElectric);
    player1.addCardToBench(new TrainerCard("Ash", "Heal all your action pokemon"));
    player1.addCardToBench(&pokemonPikachu);
    player1.activatePokemonCard(&pokemonPikachu);
    player1.attachEnergyCard(&pokemonPikachu, &energyElectric);
    player1.attachEnergyCard(&pokemonPikachu, &energyElectric);
    


    
    // pokemon.displayInfo();

}