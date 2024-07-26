#include "dwarf.h"

Dwarf::Dwarf(int x , int y) : Enemies{x,y} {
    race = "dwarf";
    hp = 100;
    atk = 20;
    def = 30;
}

// void Dwarf::attack(Player *) {}
void Dwarf::attackedBy(Player * enemy) {}
void Dwarf::dropGold() {}
Dwarf::~Dwarf() {}
