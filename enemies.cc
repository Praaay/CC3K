#include "enemies.h"

Enemies::Enemies(int x , int y) : Character{'E',x,y} {
    isPlayer = false;
}
void Enemies::dropGold() {}
void Enemies::gg(){}
//void Enemies::move(Floor floor, std::string direction) {}
Enemies::~Enemies() {}

