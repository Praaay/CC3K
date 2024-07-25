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
    player->move(floor,direction);
}


void Game::setPlayerRace(std::string race) {
    player->setRace(race);
}