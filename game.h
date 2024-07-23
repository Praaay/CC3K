#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include <character.h>

#include <stairs.h> 
#include <level.h>
#include <potion.h>
#include <floor.h>
#include <treasure.h>

using namespace std;

class Game {

    unique_ptr<Enemies*> enemies;
    unique_ptr<Potions*> potions;
    Player* player;


  public:


}





#endif
