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

class Game : public Floor , public Treasure {

    // unique_ptr<Enemies*> enemies;
    // unique_ptr<Potions*> potions;
    Player * player;
    Floor * floor;
    // Game(Floor &floor);
    void render();
    void getTick();
    void getCol();
    void newGame();
    void nextFloor();
    void printMessage();
};





#endif
