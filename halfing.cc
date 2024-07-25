#include "halfing.h"

Halfing::Halfing(int row, int col) : Enemies{row, col, 15, 20, 100, "Halfling", 'L'} { }

void Halfing::dropGold() {}
Halfing::~Halfing() {}