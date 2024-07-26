#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemies.h"

class Merchant : public Enemies {
    public:
    Merchant(int x , int y);
     // void attack(Player *) override;
     void attackedBy(Player * ) override;
     void dropGold() override;
     ~Merchant();
};

#endif