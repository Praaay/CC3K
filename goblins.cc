#include "goblins.h"

Goblin::Goblin(int x , int y) : Player{x,y} {
    hp = 110;
    atk = 15;
    def = 20;
}


Goblin::~Goblin() {}
