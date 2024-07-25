#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemies.h"

class Merchant : public Enemies {
    public:
    Merchant(int row, int col);
     void dropGold() override;
     ~Merchant();
};

#endif