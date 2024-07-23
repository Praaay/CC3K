#include "character.h"
#include <string.h>

Character::Character(char display, int x , int y) : symbol{display} , row{x}, col{y} {}

int Character::getAtk() {
    return atk;
}

int Character::getDef() {
    return def;
}
int Character::getHp() {
    return hp;
}
void Character::setAtk(int atk) {
    this->atk = atk;
}

void Character::setDef(int def) {
    this->def = def;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

void Character::setPosition(int row, int col) {
    this->row = row;
    this->col = col;
}

void Character::move(std::string direction) {
    int newRow, newCol;

    if (direction == "no") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "so") {
        newRow = row - 1;
        newCol = col;
    } else if  (direction == "so") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "ea") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "we") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "ne") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "nw") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "se") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "sw") {
        newRow = row - 1;
        newCol = col;
    }
    setPosition(newRow,newCol);
}

Character::~Character() {}