#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <memory>
#include "potion.h"
#include <vector>
#include "treasure.h"

#include "normal.h"
#include "small.h"
#include "merchanthoard.h"
#include "dragonhoard.h"


#include "enemies.h"
#include "elf.h"
#include "human.h"
#include "dwarf.h"
#include "merchant.h"
#include "dragon.h"
#include "halfing.h"
#include "orcs.h"


using namespace std;

class Abstractlevel {

    protected:
    vector<unique_ptr<Potion> > potions;
    std::vector<unique_ptr<Treasure> > treasure;
    std::vector<unique_ptr<Enemies> > enemies;

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