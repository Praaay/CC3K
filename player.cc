#include "player.h"

Player::Player(int x , int y) : Character{'@',x,y} {
    goldCount = 0;
    race = "drow";
}

// void Player::move(Floor floor, std::string direction) {

// }

int Player::getGold() {
    return goldCount;
}
void Player::setRace( std::string tmp_race) {
    this->race = tmp_race;
} 

std::string Player::getRace() {
    return race;
}

void Player::gg() {

}

void Player::attack(std::string direction) {

}

void Player::attackedBy(Enemies * enemy ) {
    
}

Player::~Player() {
    
}