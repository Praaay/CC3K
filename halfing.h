#ifndef HALFING_H
#define HALFING_H
#include "enemies.h"

class Halfing : public Enemies {
    public:
     Halfing(int row, int col);
     void dropGold() override;
     ~Halfing();
};

#endif