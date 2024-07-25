#include "potion.h"
#include <string>

Potion::Potion(int row, int col, int value, string type) : row{row}, col{col}, val{value}, type{type} {}

int Potion::getVal() {
    return val;
}

string Potion::getType() {
    return type;
}

int Potion::getRow() {
    return row;
}

int Potion::getCol() {
    return col;
}

