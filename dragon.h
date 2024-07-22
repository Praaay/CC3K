#ifndef DRAGON_H
#define DRAGON_H
#include "enemies.h"

class Dragon : public Enemies {
    public:
     void attack(Player *) override;
     void attackedBy(Player * ) override;
     void dropGold() override;
     ~Dragon();
};

#endif