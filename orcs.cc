#include "orcs.h"

Orcs::Orcs(int row, int col) : Enemies{row, col, 30, 25, 180, "Orcs", 'O'} { }

void Orcs::attack(Player *) {}
void Orcs::dropGold() {}
Orcs::~Orcs() {}