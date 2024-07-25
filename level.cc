#include "level.h"

#include <unistd.h>

Level::Level() {}
void Level::generateEnemies() {}
void Level::generatePotion() {}
void Level::generatetairs() {}

void Level::generateTreasure() {
    PRNG prng1;
    uint32_t seed = getpid();
    prng1.seed(seed);

    for (int i = 0; i < 10; i++) {

    int value = prng1(1,8);
    unique_ptr<Treasure> tmp;

    if (1 <= value && value <= 5) {
        tmp = make_unique<Normal>(3, 15 - i);
    } else if (5 < value && value <= 6) {
        tmp = make_unique<DragonHoard>(3, 15 - i);
    } else if (6 < value && value <= 8) {
        tmp = make_unique<Small>(3,15 - i);
    }
    treasure.push_back(std::move(tmp)); 
    }
}

std::vector<unique_ptr<Treasure>> Level::getTreasure() {
    return (std::move(treasure));
}


void Level::generatePlayers() {}
Level::~Level() {}

