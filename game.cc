#include "game.h"

#include <cmath> 
#include <unistd.h>
#include <vector>

//Game::Game(Floor &floor) : floor{floor} {}



Game::Game()  {


    isPlayerAlive = true;
    
   
}

void Game::setGamePlayerRace(std::string tmp_race) {
    playerRace = tmp_race;
}

std::string Game::getGamePlayerRace() {
    return playerRace;
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

void Game::newGame(){
    levelnumber = 0;
    isEnemyMove = true;
    newLevel();
}

int Game::getLevelNumber() {
    return levelnumber;
}

void Game::setLevelNumber(int new_level) {
    levelnumber = new_level;
}

void Game::newLevel() {

    treasure.clear();
    enemies.clear();
    potions.clear();

    floor.generateFloor();

    level.generatePlayers(floor,playerRace);
    level.generateTreasure();
    level.generateEnemies();
    level.generatePotion();
    level.generateStairs(floor);

    stair = level.getStairs();
    player = level.getPlayer();    
    enemies = level.getEnemies();
    treasure = level.getTreasure();
    spawnDragon();
    potions = level.getPotions();

    levelnumber++;

    setPlayerStatus(true);
    for (auto &t : treasure) {
        floor.setChar(t->getRow(),t->getCol(),'G');     
    }


    for (const auto &en : enemies) {
        int tempRow = en->getRow();
        int tempCol = en->getCol();

        std::string tempRace = en->getRace();

        if (tempRace == "elf") {
            floor.setChar(tempRow,tempCol,'E');    
        } else if (tempRace == "dragon") {
            floor.setChar(tempRow,tempCol,'D');    
        } else if (tempRace == "orc") {
            floor.setChar(tempRow,tempCol,'O');    
        } else if (tempRace == "merchant") {
            floor.setChar(tempRow,tempCol,'M');    
        } else if (tempRace == "halfing") {
            floor.setChar(tempRow,tempCol,'L');    
        } else if (tempRace == "human") {
            floor.setChar(tempRow,tempCol,'H');    
        } else if (tempRace == "dwarf") {
            floor.setChar(tempRow,tempCol,'W');    
        }    
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

    cout<<"Race: "<<race<<" Gold: "<<goldcount<<" Level: "<<levelnumber<<endl;
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
    } else if (floor.charAt(newRow,newCol) == '\\') {
        newLevel();
    }

    player->move(floor,direction);

    if (isEnemyMove) {
     randommovement();
    }

    int player_row = player->getRow();
    int player_col = player->getCol();


    attackPlayer();
}

void Game::stopEnemy() {
    isEnemyMove = false;
}



std::vector<std::vector<int>> Game::getAllNeighoubourPoints(int curRow, int curCol) {
    std::vector<std::vector<int>> neighbours;
    int maxRow = floor.floormap.size();
    int maxCol = floor.floormap[0].size();

    std::vector<std::pair<int, int>> directions = {
        {curRow - 1, curCol},      // N
        {curRow - 1, curCol + 1},  // NE
        {curRow, curCol + 1},      // E
        {curRow + 1, curCol + 1},  // SE
        {curRow + 1, curCol},      // S
        {curRow + 1, curCol - 1},  // SW
        {curRow, curCol - 1},      // W
        {curRow - 1, curCol - 1}   // NW
    };

    for (const auto& dir : directions) {
        int newRow = dir.first;
        int newCol = dir.second;
        if (newRow >= 0 && newRow < maxRow && newCol >= 0 && newCol < maxCol) {
            neighbours.push_back({newRow, newCol});
        }
    }

    return neighbours;
}



void Game::randommovement() {

    const int levelHeight = 25;
    const int floorwidth = 79;

    int index = 1;

    for(int i = 0; i < levelHeight; i++){
   for(int j = 0; j < floorwidth; j++){
     if (floor.charAt(i,j) == 'E' || floor.charAt(i,j) == 'D'|| floor.charAt(i,j) == 'M'|| floor.charAt(i,j) == 'L' || floor.charAt(i,j) == 'H' || floor.charAt(i,j) == 'O' || floor.charAt(i,j) == 'W') {

        int curRow = i;
        int curCol = j;
        std::vector<std::vector<int>> tmp = getAllNeighoubourPoints(curRow,curCol);

        Enemies* enemyAtCurrentPos = nullptr;
        
        for (auto n = enemies.begin(); n != enemies.end(); n++) {
            if((*n)->getRow() == curRow && (*n)->getCol() == curCol ) {
                enemyAtCurrentPos = (*n).get();
                break;
            }
        }


       if (! enemyAtCurrentPos->getHasMoved() && enemyAtCurrentPos->getRace() != "dragon") {       
       while (true) {

        int randIndex = std::rand() % 8; 
        int newRow = tmp[randIndex][0];
        int newCol = tmp[randIndex][1];

        if (floor.charAt(newRow,newCol) == '.') {

            char enem_char;

            if (enemyAtCurrentPos->getRace() == "elf") {
                enem_char = 'E';
            } else if (enemyAtCurrentPos->getRace() == "dragon") {
                enem_char = 'D';
            } else if (enemyAtCurrentPos->getRace() == "dwarf") {
                enem_char = 'W';
            } else if (enemyAtCurrentPos->getRace() == "human") {
                enem_char = 'H';
            } else if (enemyAtCurrentPos->getRace() == "orc") {
                enem_char = 'O';    
            } else if (enemyAtCurrentPos->getRace() == "merchant") {
                enem_char = 'M';    
            } else if (enemyAtCurrentPos->getRace() == "halfing") {
                enem_char = 'L';    
            }
            enemyAtCurrentPos->setPosition(newRow,newCol);
            enemyAtCurrentPos->setHasMoved(true);
            floor.setChar(newRow,newCol,enem_char);
            floor.setChar(curRow,curCol,'.');
            break;
        }
    }
       }
     }
   }
}

for (auto n = enemies.begin(); n != enemies.end(); n++) {
    (*n)->setHasMoved(false);
}

//cout<<"The number of playre is "<<index<<endl;

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

    //cout<<"The player health before the attck"<<player->getHp()<<endl;
    for (auto it = enemies.begin() ; it != enemies.end(); ++it) {

        if ((*it)->inRange(player.get())) { 

          if ((*it)->getRace() != "merchant")   {
            (*it)->attack(player.get());

            if ((*it)->getRace() == "elf" && player->getRace() != "Drow" ) {
            (*it)->attack(player.get());  
          }
          } else if ((*it)->getRace() == "merchant" && player->getMerchAttack()) {
            (*it)->attack(player.get());
          } 

         
        }
    }

        

    if (player->getHp() <= 0) {
        cout<<"The player shoould die"<<endl;
        setPlayerStatus(false);
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
    int boost = 1;

    if (playerRace == "Drow") {
        boost = 1.5;
    }

    // find the potion we're dealing with
    for (auto& ps : potions) {
        if (ps->getRow() == row && ps->getCol() == col) {
            type = ps->getType();
            val = ps->getVal();
            break;
        }
    }

    // cout << "row: " << row << " col: " << col << endl;
    // cout << "type: " << type <<  " val: " << val << endl;

    // apply potion and record usage
    if (type == "RH" || type == "PH") {
        player->setHp(boost * (player->getHp() + val));
    } else if (type == "BA" || type == "WA") {
        if (type == "BA") {
            player->setBACount(boost * (player->getBACount() + 1));
        } else {  // "WA"
            player->setWACount(boost * (player->getWACount() + 1));
        }
        player->setAtk(boost * (player->getAtk() + val));
    } else if (type == "BD" || type == "WD") {
        if (type == "BD") {
            player->setBDCount(boost * (player->getBDCount() + 1));
        } else {  // "WD"
            player->setWDCount(boost * (player->getWDCount() + 1));
        }
        player->setDef(boost * (player->getDef() + val));
    }

    // cout << "row: " << row << " col: " << col << endl;
    // cout << "type: " << type <<  " val: " << val << endl;

    for (auto ps = potions.begin(); ps != potions.end(); ++ps) {
        if ((*ps)->getRow() == row && (*ps)->getCol() == col) {
            potions.erase(ps);
            break;
        }
    }

    // cout << "row: " << row << " col: " << col << endl;
    // cout << "type: " << type <<  " val: " << val << endl;

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


void Game::playerattack(int currentRow, int currentCol){

    Enemies *target;

    bool isEnemy = false;
    for(int i = 0; i < enemies.size(); i++){
        if(enemies[i]->getRow() == currentRow && enemies[i] ->getCol() == currentCol){
            isEnemy = true;
            target = enemies[i].get();

        }
    } 
    if(isEnemy){
        //cout<<"The player health before the attack: "<<target->getHp()<<endl;
        int val = player->attack(target);
        //cout<<"The player health after the attack: "<<target->getHp()<<endl;

        if (target->getHp() <= 0 ) {
              int tmp_row = target->getRow();
              int tmp_col = target->getCol();
              enemyDeath(tmp_row,tmp_col);
        }

        if(val == 0){
            std::cout << "Missed the attack." << std::endl;
        }
        else{
            std::cout << "Attacked the enemy by " << val << std::endl;
        }
    }
    else{
        std::cout << "No enemy in this direction" << std::endl;
    }
}

void Game::enemyDeath(int tmp_row, int tmp_col) {

    for(auto n = enemies.begin(); n != enemies.end(); n++ ) {

        if((*n)->getRow() == tmp_row && (*n)->getCol() == tmp_col) {

            if((*n)->getRace() != "dragonhoard" && (*n)->getRace() != "human" && (*n)->getRace() != "merchant" ) {
                int value = std::rand() % 2;
                int curGold = player->getGold();

                if (value == 0) {
                    curGold = curGold + 2;
                    player->setGold(curGold);
                } else {
                    curGold = curGold + 1;
                    player->setGold(curGold);
                }
            }
            n = enemies.erase(n);
        } else {
            ++n;
        }
    }
    char reference = floor.referenceCharAt(tmp_row,tmp_col);
    floor.setChar(tmp_row,tmp_col,reference);
}



void Game::spawnDragon(){
    int row;
    int col;
    for (auto n = treasure.begin(); n != treasure.end(); ++n) {
        if((*n)->getGoldType() == "dragonhoard"){
            row = (*n)->getRow();
            col = (*n)->getCol();
            std::vector<std::vector<int>> tmp = getAllNeighoubourPoints(row, col);
            while (true) {
                int randIndex = std::rand() % 8; 
                int newRow = tmp[randIndex][0];
                int newCol = tmp[randIndex][1];

                if (floor.charAt(newRow,newCol) == '.') {
                    char enem_char = 'D';
                    unique_ptr<Enemies> dragon = make_unique<Dragon>(newRow, newCol, (*n).get());
                    dragon->setPosition(newRow, newCol);
                    floor.setChar(newRow,newCol,enem_char);
                    enemies.push_back(std::move(dragon));
                    break;
                }
            }
        }
    }
}



void Game::coverDragonHoard(int newRow, int newCol){
    floor.referenceSetAt(newRow, newCol, 'G');
    floor.setChar(newRow, newCol, '.');
    for(auto& enemy : enemies){
        if(enemy->getRace() == "dragon"){
            Treasure* dragonhoard = enemy->getassociatedDH();
            if(dragonhoard->getRow() == newRow && dragonhoard->getCol() == newCol){
                if(enemy->getHp()<= 0){
                    floor.referenceSetAt(newRow, newCol, '.');
                }
                break;
        }
        }
    }
}
void Game::changeFromAttack(){
    for(auto& enemy: enemies){
        if(enemy->getHp()<= 0){
            floor.setChar(enemy->getRow(), enemy->getCol(), '.');
        }
    }
}