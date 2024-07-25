#ifndef SHADE_H
#define SHADE_H

#include "player.h"

class Shade : public Player {
    public:
    Shade(int x , int y);
    void attack(. std::string direction) override;
     ~Shade();
};

#endif