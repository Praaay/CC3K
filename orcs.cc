#include "orcs.h"

Orcs::Orcs(int x , int y) : Enemies{x,y} {
    race = "orc";
    hp = 130;
    atk = 30;
    def = 25;
}

void Orcs::dropGold() {}
Orcs::~Orcs() {}