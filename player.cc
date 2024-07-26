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
        setHp(0);
        setAtk(0);
        setDef(0);
        setRace("");
}

int Player::attack(Enemies *target) {

}

Player::~Player() {
    
}


void Player::resetPotionEffect() {
    setAtk(getAtk() - (POTION_VAL * BACount));
    setAtk(getAtk() + (POTION_VAL * WACount));
    setDef(getDef() - (POTION_VAL * BDCount));
    setDef(getDef() + (POTION_VAL * WDCount));

    BACount = 0;
    BDCount = 0;
    WACount = 0;
    WDCount = 0;
}

int Player::getBACount() {
    return BACount;
}
int Player::getBDCount() {
    return BDCount;
}
int Player::getWACount() {
    return WACount;
}
int Player::getWDCount() {
    return WDCount;
}
void Player::setBACount(int count) {
    BACount = count;
}
void Player::setBDCount(int count) {
    BDCount = count;
}
void Player::setWACount(int count) {
    WACount = count;
}
void Player::setWDCount(int count) {
    WDCount = count;
}


