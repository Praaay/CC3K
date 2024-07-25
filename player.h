#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <memory>


class Enemies;

class Player : public Character {
    protected:
    std::string race;
    int goldCount; 

    int BACount, BDCount, WACount, WDCount;  // track the count of potion used

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


    void resetPotionEffect();  // remove the effect of potions
    int getBACount();
    int getBDCount();
    int getWACount();
    int getWDCount();

    void setBACount(int count);
    void setBDCount(int count);
    void setWACount(int count);
    void setWDCount(int count);


};

#endif