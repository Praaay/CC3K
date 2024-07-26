#ifndef ORCS_H
#define ORCS_H
#include "enemies.h"

class Orcs : public Enemies {
    public:
     Orcs(int x , int y);

     void dropGold() override;
     ~Orcs();
};

#endif