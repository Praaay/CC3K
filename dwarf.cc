#include "dwarf.h"


Dwarf::Dwarf(int x , int y) : Enemies{x,y} {
    hp = 140;
    atk = 30;
    def = 10;
}

// void Dwarg::attack(Player *) {}
void Dwarf::attackedBy(Player * enemy) {}
void Dwarf::dropGold() {}
Dwarf::~Dwarf() {}