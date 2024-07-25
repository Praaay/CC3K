#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <string>
#include "player.h"


class Enemies : public Character {
    protected:
    bool hasMoved;

    public:
    Enemies(int row, int col, int atk, int def, int hp, std::string race, char display);
    virtual void attack(Player *player);

    virtual void dropGold();
    //void move(Floor floor, std::string direction, char symbol) override;
    void gg() override;   
    virtual ~Enemies();
};

#endif