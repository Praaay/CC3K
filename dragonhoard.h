#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H
#include "treasure.h"

class DragonHoard : public Treasure{
    bool locked;
    public:
    DragonHoard(int row, int col);
    bool checklocked() override;
    void setlocked() override;
};


#endif