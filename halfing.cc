#include "halfing.h"

Halfing::Halfing(int x , int y) : Enemies{x,y} {
    race = "Halfing";
    hp = 100;
    atk = 15;
    def = 20;
}


void Halfing::dropGold() {}
Halfing::~Halfing() {}