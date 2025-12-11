#include "Card.h"
#include "EnergyCard.h"
#include "PokemonCard.h"

#include <string>
#include <vector>

using namespace std;

int main(){
    string nomCarteEnergy = "Feu";

    EnergyCard energy= EnergyCard(nomCarteEnergy);
    energy.displayInfo();

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
    PokemonCard pokemon = PokemonCard(nomCartePokemon, typePokemon, famillePokemon, niveauEvolution, pointsDeVieMax, pointsDeVieActuels, attaques);
    pokemon.displayInfo();

}