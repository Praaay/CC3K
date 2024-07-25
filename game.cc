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


int Game::newRowWrtPlayer(string direction) {
    int row = player->getRow();
    
    if (direction == "no") {
        --row;
    } else if (direction == "so") {
        ++row;
    } else if (direction == "ne") {
        --row;
    } else if (direction == "nw") {
        --row;
    } else if (direction == "se") {
        ++row;
    } else if (direction == "sw") {
        ++row;
    }

    return row;
}


int Game::newColWrtPlayer(string direction) {
    int col = player->getCol();
    
    if (direction == "ea") {
        ++col;
    } else if (direction == "we") {
        --col;
    } else if (direction == "ne") {
        ++col;
    } else if (direction == "nw") {
        --col;
    } else if (direction == "se") {
        ++col;
    } else if (direction == "sw") {
        --col;
    }

    return col;
}


void Game::usePotion(int row, int col) {
    string type;
    int val;

    // find the potion we're dealing with
    for (auto& ps : potions) {
        if (ps->getRow() == row && ps->getCol() == col) {
            type = ps->getType();
            val = ps->getVal();
        }
    }

    // apply potion and record usage
    if (type == "RH" || type == "PH") {
        player->setHp(player->getHp() + val);
    } else if (type == "BA" || type == "WA") {
        if (type == "BA") {
            player->setBACount(player->getBACount() + 1);
        } else {  // "WA"
            player->setWACount(player->getWACount() + 1);
        }
        player->setAtk(player->getAtk() + val);
    } else if (type == "BD" || type == "WD") {
        if (type == "BD") {
            player->setBDCount(player->getBDCount() + 1);
        } else {  // "WD"
            player->setWDCount(player->getWDCount() + 1);
        }
        player->setDef(player->getDef() + val);
    }


}


void Game::resetChar(int row, int col) {
    char reference = floor.referenceCharAt(row, col);
    floor.setChar(row,col,reference);
}


