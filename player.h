#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <memory>


class Enemies;

class Player : public Character {
    protected:
    std::string race;
    int goldCount; 

    public:
    Player(int x , int y);
    virtual void attack(std::string direction);
    virtual void attackedBy(Enemies * enemy );
   // void move(Floor floor, std::string direction) override;
    int getGold();
    void setRace(std::string tmp_race);
    std::string getRace();
    void gg() override; 
    virtual ~Player();  
};

#endif