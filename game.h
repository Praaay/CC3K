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

// #include <level.h>
// #include <potion.h>
#include "abstractlevel.h"
#include "level.h"
#include "floor.h"
#include "treasure.h"


#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "shade.h"
#include "goblins.h"

using namespace std;

class Game {

    // unique_ptr<Enemies*> enemies;
    // unique_ptr<Potions*> potions;
    protected:
    unique_ptr<Player> player;
    std::vector<unique_ptr<Treasure>> treasure;
    


    Floor floor;
    Level level;


    public:
  //  Game(Floor &floor);
    Game(std::string tmp_race);
    Floor getFloor();

    void setPlayerRace(std::string race);
    void moveplayer(std::string direction);
    void render();
    void getTick();
    void getCol();
    void newGame();
    void nextFloor();
    void printMessage();
    void pickupPlayerGold(int newRow,int newCol);
};





#endif
