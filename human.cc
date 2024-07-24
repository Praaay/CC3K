#include "human.h"

Human::Human(int x , int y) : Enemies{x,y} {
    hp = 140;
    atk = 20;
    def = 20;
}

// void Human::attack(Player *) {}
// void Human::attackedBy(Player *) {}
void Human::dropGold() {}
Human::~Human() {}