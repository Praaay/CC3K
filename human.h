#ifndef HUMAN_H
#define HUMAN_H
#include "enemies.h"

class Human : public Enemies {
    public:
     void attack(Player *) override;
     void attackedBy(Player * ) override;
     void dropGold() override;
     ~Human();
};

#endif