#ifndef ORCS_H
#define ORCS_H
#include "enemies.h"

class Orcs : public Enemies {
    public:
     void attack(Player *) override;
     void attackedBy(Player * ) override;
     void dropGold() override;
     ~Orcs();
};

#endif