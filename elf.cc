#include "elf.h"

Elf::Elf(int x , int y) : Enemies{x,y} {
    race = "Elf";
    hp = 140;
    atk = 30;
    def = 10;
}

void Elf::dropGold() {}
Elf::~Elf() {}