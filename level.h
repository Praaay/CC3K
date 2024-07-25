#ifndef LEVEL_H
#define LEVEL_H
#include "abstractlevel.h"

class Level : public Abstractlevel {
    
    public:
    Level();
    void generatePotion() override;
    void generateTreasure() override;

    unique_ptr<Treasure> getTreasure();

    void generatetairs() override;
    void generateEnemies() override;
    void generatePlayers() override;
    ~Level();
};

#endif