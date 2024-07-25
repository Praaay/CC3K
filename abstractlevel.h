#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

class Abstractlevel {
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