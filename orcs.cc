#include "orcs.h"

Orcs::Orcs(int x , int y) : Enemies{x,y} {
    hp = 130;
    atk = 30;
    def = 25;
}

void Orcs::attack(Player *) {}
void Orcs::attackedBy(Player *) {}
void Orcs::dropGold() {}
Orcs::~Orcs() {}