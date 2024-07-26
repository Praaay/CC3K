#include "drow.h"

Drow::Drow(int x , int y) : Player{x,y} {
    hp = 150;
    atk = 25;
    def = 15;
    maxHp = hp;
    race = "Drow";
}


Drow::~Drow() {}