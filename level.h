#ifndef LEVEL_H
#define LEVEL_H
#include "abstractlevel.h"

class Level : public Abstractlevel {
    
    public:
    Level();
    void generatePotion() override;
    void generateTreasure() override;
    void generatetairs() override;
    void generateEnemies() override;
     void generatePlayers() override;
    ~Level();
};

#endif