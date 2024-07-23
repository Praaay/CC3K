#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow : public Player {
    public:
    Drow(int x , int y);
    void attack(std::string direction) override;
    void attackedBy(Enemies * enemy ) override;
     ~Drow();
};

#endif