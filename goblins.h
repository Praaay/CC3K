#ifndef GOBLIN_H
#define GOBLIN_H
#include "player.h"


class Goblin : public Player {
    public:
    Goblin(int x , int y);
    void attack(std::string direction) override;
     ~Goblin();
};

#endif