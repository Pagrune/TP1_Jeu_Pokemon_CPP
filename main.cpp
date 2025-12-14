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
    

    Player player2("Germain");

    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "Heal all your action pokemon"));
    PokemonCard pokemonBulbizarre = PokemonCard(
        "Bulbasaur",
        "Grass",
        "Bulbasaur",
        1,
        100,
        2,
        {make_tuple(2, "Leech Seed", 15), make_tuple(3, "Vine Whipe", 25)}
    );

    player2.addCardToBench(&pokemonBulbizarre);
    player2.activatePokemonCard(&pokemonBulbizarre);
    player2.attachEnergyCard(&pokemonBulbizarre, player2.getBenchCards()[0]);
    
    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();
    cout << endl;





    
    // pokemon.displayInfo();

}