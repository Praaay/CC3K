#ifndef SHADE_H
#define SHADE_H

#include "player.h"

class Shade : public Player {
    public:
    void attack(std::string direction) override;
    void attackedBy(Enemies * enemy ) override;
     ~Shade();
};

#endif