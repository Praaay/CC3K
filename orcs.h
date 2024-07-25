#ifndef ORCS_H
#define ORCS_H
#include "enemies.h"

class Orcs : public Enemies {
    public:
     Orcs(int row, int col);
     void attack(Player *) override;
     void dropGold() override;
     ~Orcs();
};

#endif