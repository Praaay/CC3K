#include "dragon.h"

Dragon::Dragon(int x , int y) : Enemies{x,y} {
    race = "dragon";
    hp = 150;
    atk = 20;
    def = 20;
}

void Dragon::dropGold() {}
Dragon::~Dragon() {}