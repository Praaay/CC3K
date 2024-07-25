#include "level.h"
#include "PRNG.h"
#include <unistd.h>

Level::Level() {}
void Level::generateEnemies() {}
void Level::generatePotion() {}
void Level::generatetairs() {}

void Level::generateTreasure() {
    // PRNG prng1;
    // uint32_t seed = getpid();
    // prng1.seed(seed);

    // for (int i = 0; i < 10; i++) {
    // int value = prng1(1,8);

    // if (1 <= value && value <= 5) {

    // } else if (5 < value)

    // }
    

    //treasure = make_unique<Normal>(3,7);
}

unique_ptr<Treasure> Level::getTreasure() {
  //  return std::move(treasure);
}


void Level::generatePlayers() {}
Level::~Level() {}

