#include "dragonhoard.h"

DragonHoard::DragonHoard(int row, int col) : Treasure{row,col} {
    value = 6;
    goldType = "dragonhoard";
}