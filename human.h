#ifndef HUMAN_H
#define HUMAN_H
#include "enemies.h"

class Human : public Enemies {
    public:
     Human(int row, int col);
     void dropGold() override;
     ~Human();
};

#endif