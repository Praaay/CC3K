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

    isPlayerAlive = true;
}

bool Game::getPlayerStatus() {
    return isPlayerAlive;
}

void Game::setPlayerStatus(bool updated_status) {
    this->isPlayerAlive = updated_status;
}

Floor Game::getFloor() {
    return floor;
}
void Game::newGame() {
    floor.generateFloor();
    level.generateTreasure();

    level.generateEnemies();
    enemies = level.getEnemies();

    level.generatePotion();

    treasure = level.getTreasure();
    potions = level.getPotions();
    // treasure = make_unique<Normal>(3,7);
    // floor.setChar(3,7,'G');

    for (auto &t : treasure) {
        floor.setChar(t->getRow(),t->getCol(),'G');
        //cout<<"The coordinates are "<<t->getRow()<<" "<<t->getCol()<<endl;       
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
    //cout<<"The si ze of the vector is "<<potions.size()<<endl;

}

void Game::moveplayer(std::string direction) {

    int newRow = player->getRow();
    int newCol = player->getCol();
    int player_hp = player->getHp();

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
    } 

    player->move(floor,direction);
    int player_row = player->getRow();
    int player_col = player->getCol();


    attackPlayer();
    


}

void Game::playerDeath() {
    int player_row = player->getRow();
    int player_col = player->getCol();
    int prev_char = floor.referenceCharAt(player_row,player_col);

    player->gg();
    player.reset();
    floor.setChar(player_row,player_col,prev_char);


}

void Game::attackPlayer() {
    int player_row = player->getRow();
    int player_col = player->getCol();
    int index = 0;

    cout<<"The player health before the attck"<<player->getHp()<<endl;
    for (auto it = enemies.begin() ; it != enemies.end(); ++it) {
        if ((*it)->inRange(player.get())) {  
     //     cout<<"The player can be attacked "<<index<<endl;    
          ++index;      
          (*it)->attack(player.get());    
        }
    }
    cout<<"The player health after the attck"<<player->getHp()<<endl;

    if (player->getHp() <= 0) {
        cout<<"The player shoould die"<<endl;
        // Player* rawPlayer = player.release()
        // delete player;
        setPlayerStatus(false);
     //   player.reset();
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
            break;
        }
    }

    cout << "row: " << row << " col: " << col << endl;
    cout << "type: " << type <<  " val: " << val << endl;

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

    cout << "row: " << row << " col: " << col << endl;
    cout << "type: " << type <<  " val: " << val << endl;

    for (auto ps = potions.begin(); ps != potions.end(); ++ps) {
        if ((*ps)->getRow() == row && (*ps)->getCol() == col) {
            potions.erase(ps);
            break;
        }
    }

    cout << "row: " << row << " col: " << col << endl;
    cout << "type: " << type <<  " val: " << val << endl;

}

void Game::resetChar(int row, int col) {
    char reference = floor.referenceCharAt(row, col);
    floor.setChar(row,col,reference);
}

void Game::getpotions(){
    for(int i = 0; i < potions.size(); i++){
        cout << "row: " << potions[i]->getRow() << " col: " << potions[i]->getCol() << endl;
    }
}

void Game::Playerattack(int currentRow, int currentCol){

    Enemies *target;
    
    bool isEnemy = false;
    for(int i = 0; i < enemies.size(); i++){
        if(enemies[i]->getRoW() == currentRow && enemies[i] ->getCol() == currentCol){
            isEnemy = true;
        }
    } 
    if(isEnemy){
        int val = player->attack(target);
        if(val == 0){
            std::cout << "Missed the attack." << std::endl;
        }
    }
    else{
        std::cout << "No enemy in this direction" << std::endl;
    }
}