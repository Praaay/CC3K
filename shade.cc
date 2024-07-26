#include "shade.h"

Shade::Shade(int x , int y) : Player(x,y) {
    hp = 125;
    atk = 25;
    def = 25;
}

Shade::~Shade() {}