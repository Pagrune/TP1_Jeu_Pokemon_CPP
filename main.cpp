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
    // string nomCartePokemon = "Pikachu";
    // string typePokemon = "Electric";
    // string famillePokemon = "Pikachu";
    // int niveauEvolution = 2;
    // int pointsDeVieMax = 100;
    // int pointsDeVieActuels = 2;
    // vector<tuple<int, int, string, int>> attaques = {
    //     make_tuple(2, "Thunder bolt", 20),
    //     make_tuple(3, "Thunder strom", 30)
    // };
    // PokemonCard pokemonPikachu = PokemonCard(nomCartePokemon, typePokemon, famillePokemon, niveauEvolution, pointsDeVieMax, pointsDeVieActuels, attaques);

    PokemonCard pokemonPikachu = PokemonCard(
        "Pikachu",
        "Electric",
        "Pikachu",
        2,
        100,
        2,
        {make_tuple(2, "Thunder bolt", 20), make_tuple(3, "Thunder storm", 30)}
    );
    
    player1.addCardToBench(&energyElectric);
    player1.addCardToBench(&energyElectric);
    player1.addCardToBench(new TrainerCard("Ash", "Heal all your action pokemon"));
    player1.addCardToBench(&pokemonPikachu);


    player1.activatePokemonCard(&pokemonPikachu);
    player1.attachEnergyCard(&pokemonPikachu, &energyElectric);
    player1.attachEnergyCard(&pokemonPikachu, &energyElectric);

    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();
    cout << endl;
    


    
    // pokemon.displayInfo();

}