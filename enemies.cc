#include "enemies.h"
#include "player.h"
#include <cmath>

Enemies::Enemies(int x , int y) : Character{'E',x,y} {
    isPlayer = false;
    hasMoved = false;
}
void Enemies::dropGold() {}
// void Enemies::gg(){}


void Enemies::attack(Player * player) {

    int probab = rand();

    if (player->getHp() > 0 ) {
     if (probab % 2) {
        return;
     } else {
        int player_def = player->getDef();
        int player_hp = player->getHp();
        int damage = ceil((100.0 / (100.0 + player_def)) * atk);

        if (race == "orc" && player->getRace() == "Goblin") {
            damage = 1.5 * damage;
        }
        int new_hp = player_hp - damage;

        player->setHp(new_hp);
        
    }
    }
}

void Enemies::setHasMoved(bool newvalue) {
    this->hasMoved = newvalue;
}

bool Enemies::getHasMoved() {
    return hasMoved;
}

std::string Enemies::getRace()  {
    return race;
}

bool Enemies::inRange(Player * player) {
    // return (abs(player->getRow() - getRow()) <= 1 &&  abs(player->getCol() - getCol()) <= 1 );

    int dRow = std::abs(player->getRow() - getRow());
    int dCol = std::abs(player->getCol() - getCol());
    return (dRow <= 1 && dCol <= 1);
}

Enemies::~Enemies() {}

