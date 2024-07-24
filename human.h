#ifndef HUMAN_H
#define HUMAN_H
#include "enemies.h"

class Human : public Enemies {
    public:
     Human(int x , int y);
    //  void attack(Player *) override;
    //  void attackedBy(Player * ) override;
     void dropGold() override;
     ~Human();
};

#endif