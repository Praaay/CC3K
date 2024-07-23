#include "halfing.h"

Halfing::Halfing(int x , int y) : Enemies{x,y} {
    hp = 100;
    atk = 15;
    def = 20;
}

void Halfing::attack(Player *) {}
void Halfing::attackedBy(Player *) {}
void Halfing::dropGold() {}
Halfing::~Halfing() {}