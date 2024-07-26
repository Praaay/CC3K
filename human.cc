#include "human.h"

Human::Human(int x , int y) : Enemies{x,y} {
    race = "human";
    hp = 140;
    atk = 20;
    def = 20;
}

void Human::dropGold() {}
Human::~Human() {}