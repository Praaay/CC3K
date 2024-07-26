#include "merchant.h"

Merchant::Merchant(int x , int y) : Enemies{x,y} {
    race = "Merchant";
    hp = 30;
    atk = 70;
    def = 5;
}


void Merchant::dropGold() {}
Merchant::~Merchant() {}