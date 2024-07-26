#include "treasure.h"


Treasure::Treasure(int row, int col) : row{row} , col(col){}

int Treasure::getValue() {
    return value;
}

std::string Treasure::getGoldType() {
    return goldType;
}

void Treasure::setGoldType(std::string goldType) {
    this->goldType = goldType;
}

void Treasure::setValue(int value) {
    this->value = value;
}

int Treasure::getCol() {
    return col;
}

int Treasure::getRow() {
    return row;
}

void Treasure::setlocked(){
    return;
}

bool Treasure::checklocked(){
    return false;
}

