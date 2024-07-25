#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <memory>
#include <vector>
#include "treasure.h"

#include "normal.h"
#include "small.h"
#include "merchanthoard.h"
#include "dragonhoard.h"

using namespace std;

class Abstractlevel {

    protected:
    std::vector<unique_ptr<Treasure>> treasure;

    public:
    Abstractlevel();
    virtual void generatePotion() = 0;
    virtual void generateTreasure() = 0;
    virtual void generatetairs() = 0;
    virtual void generateEnemies() = 0;
    virtual void generatePlayers() = 0;
    virtual ~Abstractlevel();
};

#endif