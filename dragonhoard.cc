#include "dragonhoard.h"

DragonHoard::DragonHoard(int row, int col) : Treasure{row,col}, locked{true} {
    value = 6;
    goldType = "dragonhoard";
}

bool DragonHoard::checklocked(){
    return locked;
}
void DragonHoard::setlocked(){
    locked = false;
}