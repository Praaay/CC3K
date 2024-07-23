#include "vampire.h"

Vampire::Vampire(int x , int y) : Player{x,y} {
    hp = 50;
    atk = 25;
    def = 25;
}

void Vampire::attack(std::string direction) {

}

void Vampire::attackedBy(Enemies * enemy) {
    
}

Vampire::~Vampire() {}