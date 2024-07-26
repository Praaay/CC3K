#include "troll.h"

Troll::Troll(int x , int y) : Player{x,y} {
    race = "Troll";
    hp = 120;
    atk = 25;
    def = 15;
    maxHp = hp;
}

void Troll::additionalAbility(){
  int x = getHp();
  int y = maxHp;
  hp = (x > y)? y : x;

}
Troll::~Troll() {}