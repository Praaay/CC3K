#include "dragon.h"

Dragon::Dragon(int x , int y, Treasure* dragonHoard) : Enemies{x,y}, dragonHoard{dragonHoard} {
    race = "dragon";
    hp = 150;
    atk = 20;
    def = 20;
}

Treasure* Dragon::getassociatedDH(){
    return dragonHoard;
}

void Dragon::dropGold() {}
Dragon::~Dragon() {}