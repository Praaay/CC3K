#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <memory>
#include <string>
#include "floor.h"

class Enemies;

class Player : public Character {
    protected:
    std::string race;
    int goldCount; 

    public:
    Player(int row, int col, int atk, int def, int hp, std::string race);
    virtual void attack(Floor &floor, std::string direction);
    int getGold();
    void setRace(std::string tmp_race);
    std::string getRace();

    void gg() override;
    virtual ~Player();
};

#endif