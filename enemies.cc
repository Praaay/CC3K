#include "enemies.h"
#include "player.h"
#include <cmath>

Enemies::Enemies(int x , int y) : Character{'E',x,y} {
    isPlayer = false;
}
void Enemies::dropGold() {}
// void Enemies::gg(){}


void Enemies::attack(Player * player) {

    int player_def = player->getDef();
    int player_hp = player->getHp();

    int damage = ceil((100.0 / (100.0 + player_def)) * atk);
    int new_hp = player_hp - damage;
    int probab = rand();

    if (player_hp > 0 ) {
     if (probab % 2) {
        return;
     } else {
        player->setHp(new_hp);
        
    }
    }
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

