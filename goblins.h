#ifndef GOBLIN_H
#define GOBLIN_H
#include "player.h"


class Goblin : public Player {
    public:
    void attack(std::string direction) override;
    void attackedBy(Enemies * enemy ) override;
     ~Goblin();
};

#endif