#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow : public Player {
    public:
    Drow(int row, int col);
    void attack(std::string direction) override;
     ~Drow();
};

#endif