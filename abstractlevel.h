#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <memory>
#include "potion.h"

class Abstractlevel {

    protected:
    vector<unique_ptr<Potion> > potions;

    public:
    Abstractlevel();
    virtual void generatePotion() = 0;
    virtual void generateTreasure() = 0;
    virtual void generatetairs() = 0;
    virtual void generateEnemies() = 0;
    virtual void generatePlayers() = 0;
    virtual ~Abstractlevel();

    vector<unique_ptr<Potion> > getPotions();
};

#endif