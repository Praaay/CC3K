#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire : public Player {
    public:
    Vampire(int x , int y);
    int attack(Enemies* target) override;
     ~Vampire();
};

#endif