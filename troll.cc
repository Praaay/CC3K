#include "troll.h"

Troll::Troll(int x , int y) : Player{x,y} {
  //  race = "troll";
    hp = 120;
    atk = 25;
    def = 15;
}


Troll::~Troll() {}