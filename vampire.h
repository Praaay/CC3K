#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire : public Player {
    public:
    Vampire(int x , int y);
    void attack(std::string direction) override;
    void attackedBy(Enemies * enemy ) override;
     ~Vampire();
};

#endif