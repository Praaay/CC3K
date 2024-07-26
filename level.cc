#include "level.h"

#include <unistd.h>

Level::Level() {}
void Level::generateEnemies() {
    PRNG prng1;
    uint32_t seed = getpid();
    prng1.seed(seed);   

    for (int i = 0; i < 20; i++) {
        int value = prng1(1,18);
  //      std::cout<<value<<endl;
        unique_ptr<Enemies> tmp;

        if (1 <= value && value <= 4) {
            tmp = make_unique<Human>(5,25 - i);
        } else if (4 < value && value <= 7) {
            tmp = make_unique<Dwarf>(5,25 - i);
        } else if ( 7 < value && value <= 12) {
            tmp = make_unique<Halfing>(5,25 - i);
        }else if (12 <value && value <= 14) {
            tmp = make_unique<Elf>(5,25 - i);
        } else if (14 < value && value <= 16) {
            tmp = make_unique<Orcs>(5,25 - i);
        } else if ( 16 < value && value <= 18) {
            tmp = make_unique<Merchant>(5,25 - i);
        }
        enemies.push_back(std::move(tmp));
    }
}
void Level::generatePotion() {}
void Level::generatetairs() {}

std::vector<unique_ptr<Enemies>> Level::getEnemies() {
    return (std::move(enemies));
 }

void Level::generateTreasure() {
    PRNG prng1;
    uint32_t seed = getpid();
    prng1.seed(seed);

    //std::cout<<"hello"<<endl;

    for (int i = 0; i < 10; i++) {

    int value = prng1(1,8);
  //  std::cout<<value<<endl;
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

