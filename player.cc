#include "player.h"
#include <string>

Player::Player(int row, int col, int atk, int def, int hp, std::string race) : Character{'@', row, col, atk, def, hp, race}, goldCount{0} {}

int Player::getGold() {
    return goldCount;
}

void Player::setRace(std::string tmp_race) {
    this->race = tmp_race;
} 

std::string Player::getRace() {
    return race;
}

void Player::gg() {

}

void Player::attack(Floor &floor, std::string direction) {
    // first check it's valid to attack
    int newRow = getRow();
    int newCol = getCol();

    if (direction == "no") {
        newRow--;
    } else if (direction == "so") {
        newRow++;
    } else if (direction == "ea") {
        newCol++;
    } else if (direction == "we") {
        newCol--;
    } else if (direction == "ne") {
        newRow--;
        newCol;
    } else if (direction == "nw") {
        newRow--;
        newCol--;
    } else if (direction == "se") {
        newRow++;
        newCol++;
    } else if (direction == "sw") {
        newRow++;
        newCol--;
    }
    if(floor.charAt(newRow,newCol) == 'H' || floor.charAt(newRow,newCol) == 'W' || floor.charAt(newRow,newCol) == 'E' || floor.charAt(newRow,newCol) == 'O' || floor.charAt(newRow,newCol) == 'M' || floor.charAt(newRow,newCol) == 'D' || floor.charAt(newRow,newCol) == 'L'){
        int enemey = floor.charAt(newRow, newCol);

        
    }
    else{
        std::cout << "There's no enemy there." << std::endl;
    }
}

Player::~Player() {}