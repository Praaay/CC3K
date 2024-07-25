#include "game.h"


//Game::Game(Floor &floor) : floor{floor} {}

Game::Game(std::string tmp_race)  {

    if (tmp_race == "Drow") {
        player = make_unique<Drow>(4,5);
        setPlayerRace("Drow");
    } else if (tmp_race == "Vampire") {
        player = make_unique<Vampire>(4,5);
        setPlayerRace("Vampire");
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

    treasure = level.getTreasure();

    // for (const auto &t : treasure) {

    // }

    // treasure = make_unique<Normal>(3,7);
    // floor.setChar(3,7,'G');

    for (const auto &t : treasure) {
        int tempRow = t->getRow();
        int tempCol = t->getCol();

        floor.setChar(tempRow,tempCol,'G');       
   // cout << "Treasure at (" << t->getRow() << ", " << t->getCol() << ")" <<" The type of treasure is "<<t->getGoldType()<<endl;
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
        cout<<"Hello";
        pickupPlayerGold(newRow,newCol);
    }    

   
    player->move(floor,direction);
    
}

void Game::pickupPlayerGold(int newRow,int newCol){
 
        // for (const auto &t : treasure) {
        
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
        // if(it == treasure.end()){
        //     it = treasure.erase(it);
        //     break;
        // }            
   //     cout << "Treasure at (" << t->getRow() << ", " << t->getCol() << ")" <<" The type of treasure is "<<t->getGoldType()<<endl;
    }
}

void Game::setPlayerRace(std::string race) {
    player->setRace(race);
}