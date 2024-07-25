#include "player.h"

Player::Player(int x , int y) : Character{'@',x,y} {
    goldCount = 0;
    race = "drow";
    isPlayer = true;
}

// void Player::move(Floor floor, std::string direction) {

// }

void Player::pickupGold(std::unique_ptr<Treasure> treasure) {
    int newGoldCount = treasure->getValue();
    goldCount += newGoldCount;
}

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