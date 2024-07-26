#ifndef LEVEL_H
#define LEVEL_H

#include "abstractlevel.h"
#include "PRNG.h"

using namespace std;

class Level : public Abstractlevel {
    
    int chamberAt;
    vector<vector<int>> chamber1;
    vector<vector<int>> chamber2;
    vector<vector<int>> chamber3;
    vector<vector<int>> chamber4;
    vector<vector<int>> chamber5;

    public:
    Level();

    bool inChamber(int row, int col, vector<vector<int>>& chamber);
    vector<int> randomhelper(int len, vector<vector<int>>& chamberNum);
    int randomNumberGenerater(int from, int to);

    int randomChamber();
    vector<int> randomCoordinates(); //  returns a vector of coords
    vector<int> randomChamberCoordinates(int chamber);

    unique_ptr<Player> player;
    unique_ptr<Stairs> stair;

    void generatePotion() override;
    void generateTreasure() override;

    std::vector<unique_ptr<Treasure>>  getTreasure();
    std::vector<unique_ptr<Enemies>> getEnemies();
    vector<unique_ptr<Potion> > getPotions();

    unique_ptr<Stairs> getStairs();
    unique_ptr<Player> getPlayer();

    void generateStairs(Floor &floor);
    void generateEnemies() override;
    void generatePlayers(Floor &floor , std::string tmp_race);
    ~Level();

};

#endif

