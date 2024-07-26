#ifndef LEVEL_H
#define LEVEL_H

#include "abstractlevel.h"
#include "PRNG.h"

using namespace std;

class Level : public Abstractlevel {
    
    vector<vector<int>> chamber1;
    vector<vector<int>> chamber2;
    vector<vector<int>> chamber3;
    vector<vector<int>> chamber4;
    vector<vector<int>> chamber5;

    public:
    Level();

    int randomNumberGenerater(int from, int to);

    int randomChamber();
    vector<int> randomCoordinates(); //  returns a vector of coords

    void generatePotion() override;
    void generateTreasure() override;

    std::vector<unique_ptr<Treasure>>  getTreasure();
    std::vector<unique_ptr<Enemies>> getEnemies();
    vector<unique_ptr<Potion> > getPotions();

    void generatetairs() override;
    void generateEnemies() override;
    void generatePlayers() override;
    ~Level();

};

#endif

