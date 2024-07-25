#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire : public Player {
    public:
    Vampire(int row, int col);
    void attack(std::string direction) override;
     ~Vampire();
};

#endif