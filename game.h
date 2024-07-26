#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "abstractlevel.h"
#include "character.h"
#include "player.h"
#include "stairs.h" 

#include "level.h"
#include "potion.h"
#include "abstractlevel.h"
#include "level.h"
#include "floor.h"
#include "treasure.h"


#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "shade.h"
#include "goblins.h"

#include "enemies.h"
#include "elf.h"
#include "human.h"
#include "dwarf.h"
#include "merchant.h"
#include "dragon.h"
#include "halfing.h"
#include "orcs.h"
#include "PRNG.h"


using namespace std;

class Game {

    // unique_ptr<Enemies*> enemies;
  protected:
    vector<unique_ptr<Potion> > potions;  // dumbass michael wants this
    Level level;
    unique_ptr<Player> player;
    std::vector<unique_ptr<Treasure> > treasure;
     std::vector<unique_ptr<Enemies> > enemies;
    


    Floor floor;
    public:
  //  Game(Floor &floor);
    Game(std::string tmp_race);
    Floor getFloor();

    int newRowWrtPlayer(string direction); 
    int newColWrtPlayer(string direction);
    bool isPlayerAlive;

    void resetChar(int row, int col);
    void usePotion(int row, int col);
    void setPlayerRace(std::string race);
    void moveplayer(std::string direction);
    void render();
    void getTick();
    void newGame();
    void nextFloor();
    void printMessage();
    void pickupPlayerGold(int newRow,int newCol);
    void attackPlayer();
    void getpotions();
    void playerDeath();
    bool getPlayerStatus();
    void setPlayerStatus(bool updated_status);
    void randommovement();
    std::vector<std::vector<int>> getAllNeighoubourPoints(int curRow, int curCol);
};





#endif
