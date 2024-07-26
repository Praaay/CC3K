#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemies.h"

class Merchant : public Enemies {
    public:
    Merchant(int x , int y);
     void dropGold() override;
     ~Merchant();
};

#endif