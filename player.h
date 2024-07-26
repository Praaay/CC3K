#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <memory>
#include "treasure.h"


class Enemies;

class Player : public Character {
    protected:
    std::string race;
    int goldCount; 

    int BACount, BDCount, WACount, WDCount;  // track the count of potion used
    bool isMerchAttack;
<<<<<<< HEAD
=======
    // int potionMultiplier;
>>>>>>> main

    public:
    Player(int x , int y);
    virtual int attack(Enemies *target);

   // void move(Floor floor, std::string direction) override;

    void pickupGold(std::unique_ptr<Treasure> treasure);

    int getGold();
    void setRace(std::string tmp_race);
    std::string getRace();
    void gg(); 
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

<<<<<<< HEAD
    bool getMerchAttack();
    void setMerchAttack(bool status);
=======
    void setGold(int val){
        goldCount = val;
    }
>>>>>>> main

};

#endif