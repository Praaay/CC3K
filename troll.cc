#include "troll.h"

Troll::Troll(int x , int y) : Player{x,y} {
    hp = 120;
    atk = 25;
    def = 15;
}

void Troll::attack(std::string direction) {

}

void Troll::attackedBy(Enemies * enemy) {
    
}

Troll::~Troll() {}