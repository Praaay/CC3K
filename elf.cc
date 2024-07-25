#include "elf.h"

Elf::Elf(int row, int col) : Enemies{row, col, 30, 10, 140, "Elf", 'E'} {
    hp = 140;
    atk = 30;
    def = 10;
}

void Elf::attack(Player *) {}
void Elf::dropGold() {}
Elf::~Elf() {}