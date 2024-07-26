#ifndef DRAGON_H
#define DRAGON_H
#include "enemies.h"
#include "dragonhoard.h"
class Dragon : public Enemies {
    Treasure* dragonHoard;
    public:
     Dragon(int x, int y, Treasure* dragonHoard);
     Treasure* getassociatedDH() override;
     void dropGold() override;
     ~Dragon();
};

#endif