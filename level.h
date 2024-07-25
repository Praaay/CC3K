#ifndef LEVEL_H
#define LEVEL_H
#include "abstractlevel.h"
#include "PRNG.h"

class Level : public Abstractlevel {
    
    public:
    Level();
    void generatePotion() override;
    void generateTreasure() override;

   std::vector<unique_ptr<Treasure>>  getTreasure();

    void generatetairs() override;
    void generateEnemies() override;
    void generatePlayers() override;
    ~Level();
};

#endif