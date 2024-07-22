#ifndef HALFING_H
#define HALFING_H
#include "enemies.h"

class Halfing : public Enemies {
    public:
     void attack(Player *) override;
     void attackedBy(Player * ) override;
     void dropGold() override;
     ~Halfing();
};

#endif