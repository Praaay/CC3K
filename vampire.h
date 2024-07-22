#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vapmire : public Player {
    public:
    void attack(std::string direction) override;
    void attackedBy(Enemies * enemy ) override;
     ~Vapmire();
};

#endif