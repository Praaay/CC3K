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
#include "floor.h"
#include "treasure.h"

using namespace std;

class Game {

    // unique_ptr<Enemies*> enemies;
    // unique_ptr<Potions*> potions;
    protected:
    unique_ptr<Player> player;
    Floor floor;
    public:
  //  Game(Floor &floor);
    Game();
    Floor getFloor();

    void moveplayer(std::string direction);
    void render();
    void getTick();
    void getCol();
    void newGame();
    void nextFloor();
    void printMessage();
};





#endif
