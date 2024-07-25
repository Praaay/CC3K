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
  protected:
    vector<unique_ptr<Potion> > potions;  // dumbass michael wants this
    Level level;
    unique_ptr<Player> player;
    Floor floor;


  public:
  //  Game(Floor &floor);
    Game(std::string tmp_race);
    Floor getFloor();

    int newRowWrtPlayer(string direction); 
    int newColWrtPlayer(string direction);

    void resetChar(int row, int col);
    void usePotion(int row, int col);
    void setPlayerRace(std::string race);
    void moveplayer(std::string direction);
    void render();
    void getTick();
    void newGame();
    void nextFloor();
    void printMessage();
    
};





#endif
