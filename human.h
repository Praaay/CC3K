#ifndef HUMAN_H
#define HUMAN_H
#include "enemies.h"

class Human : public Enemies {
    public:
     Human(int x , int y);

     void dropGold() override;
     ~Human();
};

#endif