#include "Card.h"
#include "EnergyCard.h"

#include <string>
#include <vector>

using namespace std;

int main(){
    string nomCarteEnergy = "Feu";

    EnergyCard energy= EnergyCard(nomCarteEnergy);
    energy.displayInfo();


}