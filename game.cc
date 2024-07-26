#include "game.h"

#include <unistd.h>
#include <vector>
//Game::Game(Floor &floor) : floor{floor} {}

Game::Game(std::string tmp_race)  {

    if (tmp_race == "Drow") {
        player = make_unique<Drow>(4,5);
        setPlayerRace("Drow");
    } else if (tmp_race == "Vampire") {
        player = make_unique<Vampire>(4,5);
        setPlayerRace("Vampire");
        potions.emplace_back(make_unique<Potion>(3, 7, 5, "WD"));

    } else if (tmp_race == "Goblin") {
        player = make_unique<Goblin>(4,5);
        setPlayerRace("Goblin");
    } else if (tmp_race == "Shade") {
        player = make_unique<Shade>(4,5);
        setPlayerRace("Shade");
    } else if (tmp_race == "Troll") {
        player = make_unique<Troll>(4,5);
        setPlayerRace("Troll");
    }
}

Floor Game::getFloor() {
    return floor;
}
void Game::newGame() {
    floor.generateFloor();
    level.generateTreasure();

    level.generateEnemies();

    treasure = level.getTreasure();
    enemies = level.getEnemies();

    level.generatePotion();

    treasure = level.getTreasure();
    potions = level.getPotions();
    // treasure = make_unique<Normal>(3,7);
    // floor.setChar(3,7,'G');


    for (const auto &t : treasure) {
        int tempRow = t->getRow();
        int tempCol = t->getCol();
        floor.setChar(tempRow,tempCol,'G');       
    }


    for (const auto &en : enemies) {
        int tempRow = en->getRow();
        int tempCol = en->getCol();

        floor.setChar(tempRow,tempCol,'E');       

    } 

    for(auto& pt : potions) {
        floor.setChar(pt->getRow(), pt->getCol(), 'P');
    }
    

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
        newCol++;
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
        pickupPlayerGold(newRow,newCol);
    } else if (floor.charAt(newRow,newCol) == 'E')  {

        PRNG prng1;
        uint32_t seed = getpid();
        prng1.seed(seed);
        int value = prng1(1,2);
    }

   
    player->move(floor,direction);
    int player_row = player->getRow();
    int player_col = player->getCol();
    attackPlayer();
    
}

void Game::attackPlayer() {
    int player_row = player->getRow();
    int player_col = player->getCol();
    int index = 0;
   

    for (auto it = enemies.begin() ; it != enemies.end(); ++it) {
        if ((*it)->inRange(player.get())) {  
          cout<<"The player can be attacked "<<index<<endl;    
          ++index;      
          (*it)->attack(player.get());    
        }
    }
}

void Game::pickupPlayerGold(int newRow,int newCol){
 
        
        for(auto it = treasure.begin(); it != treasure.end(); ++it){
        int tempRow = (*it)->getRow();
        int tempCol = (*it)->getCol();

        if (tempRow == newRow && tempCol == newCol) {
            cout<<" The type of treasure is "<< (*it)->getGoldType()<<endl;
            //pickup
            
            unique_ptr<Treasure> tmp_treasure = std::move(*it);
   
            player->pickupGold(std::move(tmp_treasure));
            
            char treasure_ref = floor.referenceCharAt(newRow,newCol);
            
            floor.setChar(tempRow,tempCol,treasure_ref);
            it = treasure.erase(it);
            break;
        }
    }
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

    for (auto ps = potions.begin(); ps != potions.end(); ) {
        if ((*ps)->getRow() == row && (*ps)->getCol() == col) {
            potions.erase(ps);
        }
    }

}

void Game::resetChar(int row, int col) {
    char reference = floor.referenceCharAt(row, col);
    floor.setChar(row,col,reference);
}
