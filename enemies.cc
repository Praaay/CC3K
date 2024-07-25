#include "enemies.h"


Enemies::Enemies(int row, int col, int atk, int def, int hp, std::string race, char display) : 
Character{display, row, col, atk, def, hp, race}, hasMoved{false} {}

void Enemies::dropGold() {}
void Enemies::gg(){}
//void Enemies::move(Floor floor, std::string direction) {}
Enemies::~Enemies() {}

