#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Enemies;

class Player : public Character {
    protected:
    int goldCount; 

    public:
    Player(int x , int y);
    virtual void attack(std::string direction);
    virtual void attackedBy(Enemies * enemy );
   // void move(Floor floor, std::string direction) override;
    void gg() override; 
    virtual ~Player();  
};

#endif