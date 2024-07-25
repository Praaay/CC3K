#include "game.h"


//Game::Game(Floor &floor) : floor{floor} {}

Game::Game(std::string tmp_race)  {

    if (tmp_race == "Drow") {
        player = make_unique<Drow>(3,5);
        setPlayerRace("Drow");
    } else if (tmp_race == "Vampire") {
        player = make_unique<Vampire>(3,5);
        setPlayerRace("Vampire");
    } else if (tmp_race == "Goblin") {
        player = make_unique<Goblin>(3,5);
        setPlayerRace("Goblin");
    } else if (tmp_race == "Shade") {
        player = make_unique<Shade>(3,5);
        setPlayerRace("Shade");
    } else if (tmp_race == "Troll") {
        player = make_unique<Troll>(3,5);
        setPlayerRace("Troll");
    }


}

Floor Game::getFloor() {
    return floor;
}
void Game::newGame() {
    floor.generateFloor();
    level.generateTreasure();

    treasure = level.getTreasure();

   
    floor.setChar(3,7,'G');

    // treasure = make_unique<Normal>(3,7);
    // floor.setChar(3,7,'G');
    
}

void Game::render() {
    floor.printFloor();
    printMessage();
}

void Game::printMessage() {

    std::string race = player->getRace();
    int goldcount = player->getGold();
    int hp = player->getHp();
    int atk = player->getAtk();
    int def = player->getDef();

    cout<<"Race: "<<race<<" Gold: "<<goldcount<<endl;
    cout<<"HP "<<hp<<endl;;
    cout<<"Atk "<<atk<<endl;
    cout<<"Def "<<def<<endl;
}

void Game::moveplayer(std::string direction) {

    int newRow = player->getRow();
    int newCol = player->getCol();

    if (direction == "no") {
        newRow--;
    } else if (direction == "so") {
        newRow++;
    } else if (direction == "ea") {
        newCol++;
    } else if (direction == "we") {
        newCol--;
    } else if (direction == "ne") {
        newRow--;
        newCol;
    } else if (direction == "nw") {
        newRow--;
        newCol--;
    } else if (direction == "se") {
        newRow++;
        newCol++;
    } else if (direction == "sw") {
        newRow++;
        newCol--;
    }

    if (floor.charAt(newRow,newCol) == 'G') {
        pickupPlayerGold();
    }    
     
    player->move(floor,direction);    
}

void Game::pickupPlayerGold(){

    int treasureRow = treasure->getRow();
    int treasureCol = treasure->getCol();

    player->pickupGold(std::move(treasure));   
    char floorChar = floor.referenceCharAt(treasureRow,treasureCol);
    floor.setChar(treasureRow,treasureCol,floorChar);
}

void Game::setPlayerRace(std::string race) {
    player->setRace(race);
}