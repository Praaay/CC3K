#include "dragon.h"

Dragon::Dragon(int x , int y) : Enemies{x,y} {
    hp = 150;
    atk = 20;
    def = 20;
}

void Dragon::attack(Player *) {}
void Dragon::attackedBy(Player *) {}
void Dragon::dropGold() {}
Dragon::~Dragon() {}