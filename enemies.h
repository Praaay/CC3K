#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player;

class Enemies : public Character {
    protected:
    bool hasMoved;  

    public:
    Enemies(int x , int y);
    virtual void attack(Player *) = 0;
    virtual void attackedBy(Player *) = 0;
    virtual void dropGold();
    void move(std::string direction) override;
    void gg() override;   
    virtual ~Enemies();
};

#endif