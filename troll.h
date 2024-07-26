#ifndef TROLL_H
#define TROLL_H
#include "player.h"

class Troll : public Player {
    public:
    Troll(int x , int y);
    void additionalAbility() override;
     ~Troll();
};

#endif

