#include "dragon.h"

Dragon::Dragon(int row, int col) : Enemies{row, col, 20, 20, 150, "Dragon", 'D'} {
    hp = 150;
    atk = 20;
    def = 20;
}

void Dragon::dropGold() {}
Dragon::~Dragon() {}