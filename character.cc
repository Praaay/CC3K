#include "character.h"
#include <string>

Character::Character(char display, int row , int col, int hp, int atk, int def, std::string race) : symbol{display}, row{row}, col{col}, atk{atk}, def{def}, hp{hp}, race{race} {}

int Character::getAtk() {
    return atk;
}

int Character::getDef() {
    return def;
}
int Character::getHp() {
    return hp;
}

int Character::getRow() {
    return row;
}

int Character::getCol() {
    return col;
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


void Character::move(Floor &floor, std::string direction, char symbol) {
  //  std::cout<<"hello";

    int newRow;
    int newCol;
   // char prev = floor.charAt(row,col);

    if (direction == "no") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "so") {
        newRow = row + 1;
        newCol = col;
    } else if  (direction == "so") {
        newRow = row - 1;
        newCol = col;
    } else if (direction == "ea") {
        newRow = row;
        newCol = col + 1;
    } else if (direction == "we") {
        newRow = row;
        newCol = col - 1;
    } else if (direction == "ne") {
        newRow = row - 1;
        newCol = col + 1;
    } else if (direction == "nw") {
        newRow = row - 1;
        newCol = col - 1;
    } else if (direction == "se") {
        newRow = row + 1;
        newCol = col + 1;
    } else if (direction == "sw") {
        newRow = row + 1;
        newCol = col - 1;
    }
    // std::cout<<"the col from the character class is "<<newCol;
    // std::cout<<"the row from the character class is "<<newRow;
   // std::cout<<"The prev char is "<<prev;

   if (floor.charAt(newRow,newCol) == '.' || floor.charAt(newRow,newCol) == '#'  || floor.charAt(newRow,newCol) == '\\' || floor.charAt(newRow,newCol) == '+' ) {
    char reference = floor.referenceCharAt(row,col);
    std::cout << row << " " << col << std::endl;
    floor.setChar(row,col,reference);
    setPosition(newRow,newCol);
    floor.setChar(newRow,newCol, symbol);
   }
}

Character::~Character() {}