#include "elf.h"

Elf::Elf(int x , int y) : Enemies{x,y} {
    race = "elf";
    hp = 140;
    atk = 30;
    def = 10;
}

// void Elf::attack(Player *) {}
void Elf::attackedBy(Player * enemy) {}
void Elf::dropGold() {}
Elf::~Elf() {}