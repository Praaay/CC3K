#include "drow.h"

Drow::Drow(int x , int y) : Player{x,y} {
    hp = 150;
    atk = 25;
    def = 15;
}

void Drow::attack(std::string direction) {

}

void Drow::attackedBy(Enemies * enemy) {

}

Drow::~Drow() {}