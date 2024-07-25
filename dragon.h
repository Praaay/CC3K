#ifndef DRAGON_H
#define DRAGON_H
#include "enemies.h"

class Dragon : public Enemies {
    public:
     Dragon(int x , int y);
     void dropGold() override;
     ~Dragon();
};

#endif