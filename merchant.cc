#include "merchant.h"

Merchant::Merchant(int x , int y) : Enemies{x,y} {
    race = "merchant";
    hp = 30;
    atk = 70;
    def = 5;
}

// void Merchant::attack(Player *) {}
void Merchant::attackedBy(Player *) {}
void Merchant::dropGold() {}
Merchant::~Merchant() {}