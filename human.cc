#include "human.h"

Human::Human(int row, int col) : Enemies{row, col, 20, 20, 140, "Human", 'H'} {}

void Human::dropGold() {}

Human::~Human() {}
