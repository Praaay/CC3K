#ifndef TROLL_H
#define TROLL_H
#include "player.h"

class Troll : public Player {
    public:
    Troll(int x , int y);
    void attack(std::string direction) override;
    void attackedBy(Enemies * enemy ) override;
     ~Troll();
};

#endif

