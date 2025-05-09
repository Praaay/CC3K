#include "level.h"
#include <unistd.h>
#include "PRNG.h"
#include <fstream>
#include <iostream>


using namespace std;

Level::Level() {

    string line;
    ifstream inp("chambermap.txt");
    int row = 0;

    while(getline(inp, line)){
        
        for(int col = 0; col < line.length(); ++col){
            std::vector<int> coord;
            char temp = line[col];
            if (temp == '1' || temp == '2' || temp == '3' || temp == '4' || temp == '5') {
                coord.push_back(row);
                coord.push_back(col);
                
                //cout << coord[0] << ", " << coord[1] << endl;
            }

            if (temp == '1') {
                chamber1.push_back(coord);
            } else if (temp == '2') {
                chamber2.push_back(coord);
            } else if (temp == '3') {
                chamber3.push_back(coord);
            } else if (temp == '4') {
                chamber4.push_back(coord);
            } else if (temp == '5') {
                chamber5.push_back(coord);
            }

        }
        ++row;
    }

    // cout << "sizeof: " << chamber1.size() << endl;
    // for(int i = 0; i < 104; i++) {
    //     vector<int> temp = chamber1[i];
    //     cout << "row: " << temp[0] << " col: " << temp[1] << endl;
    // }

}

int Level::randomNumberGenerater(int from, int to) {
    static PRNG prng1;
    static bool initialized = false;
    if (!initialized) {
        uint32_t seed = getpid();
        prng1.seed(seed);
        initialized = true;
    }
    return prng1(from, to);
}


int Level::randomChamber() {
    return randomNumberGenerater(1, 5);
}

vector<int> Level::randomhelper(int len, vector<vector<int>>& chamberNum){
    int randomNum = randomNumberGenerater(0,len - 1);
    for (int i = 0; i < len; ++i) {
        if (i == randomNum) {
            vector<int> temp = chamberNum[i];
            chamberNum.erase(chamberNum.begin() + randomNum);
            return temp;
        }
    }
    vector<int> error = {9999999, 401};
    return error;
}

vector<int> Level::randomCoordinates() {
    
    int chamber = randomChamber();


    //vector<vector<int> >& theChamber = chamber1;
    int len = 0;
    if (chamber == 1) {  //  fetch the chamber and the size of it.
        len = chamber1.size();
        return randomhelper(len, chamber1);
    } else if (chamber == 2) {
        len = chamber2.size();
        return randomhelper(len, chamber2);
    } else if (chamber == 3) {
        len = chamber3.size();
        return randomhelper(len, chamber3);
    } else if (chamber == 4) {
        len = chamber4.size();
        return randomhelper(len, chamber4);
    } else if (chamber == 5) {
        len = chamber5.size();
        return randomhelper(len, chamber5);
    }

    vector<int> error = {9999999, 401};
    return error;

}

vector<int> Level::randomChamberCoordinates(int chamber) {
    //vector<vector<int> >& theChamber = chamber1;
    int len = 0;
    if (chamber == 1) {  //  fetch the chamber and the size of it.
        len = chamber1.size();
        return randomhelper(len, chamber1);
    } else if (chamber == 2) {
        len = chamber2.size();
        return randomhelper(len, chamber2);
    } else if (chamber == 3) {
        len = chamber3.size();
        return randomhelper(len, chamber3);
    } else if (chamber == 4) {
        len = chamber4.size();
        return randomhelper(len, chamber4);
    } else if (chamber == 5) {
        len = chamber5.size();
        return randomhelper(len, chamber5);
    }

    vector<int> error = {9999999, 401};
    return error;

}

void Level::generateStairs(Floor &floor) {
    // prevent same chamber as player
    int chamber = randomNumberGenerater(1, 5);
    while (chamber == chamberAt) {
        chamber = randomNumberGenerater(1, 5);
    }

    vector<int> location = randomChamberCoordinates(chamber);
    int row = location[0];
    int col = location[1];

    stair = make_unique<Stairs>(row, col);
    floor.setChar(row,col,'\\');
}

unique_ptr<Stairs> Level::getStairs() {
    return std::move(stair);
}


void Level::generatePlayers(Floor &floor, std::string tmp_race) {

    vector<int> location = randomCoordinates();
    int row = location[0];
    int col = location[1];

        //player =  make_unique<Drow>(row,col);
        // int tmp_row = player->getRow();
        // int tmp_col = player->getCol();

    if (inChamber(row, col, chamber1)) {
        chamberAt = 1;
    } else if (inChamber(row, col, chamber2)) {
        chamberAt = 2;
    } else if (inChamber(row, col, chamber3)) {
        chamberAt = 3;
    } else if (inChamber(row, col, chamber4)) {
        chamberAt = 4;
    } else if (inChamber(row, col, chamber5)) {
        chamberAt = 5;
    }

    if (tmp_race == "Drow") {
        player = make_unique<Drow>(row,col);
        player->setRace("Drow");
    } else if (tmp_race == "Vampire") {
        player = make_unique<Vampire>(row,col);
        player->setRace("Vampire");
    } else if (tmp_race == "Goblin") {
        player = make_unique<Goblin>(row,col);
        player->setRace("Goblin");
    } else if (tmp_race == "Shade") {
        player = make_unique<Shade>(row,col);
        player->setRace("Shade");
    } else if (tmp_race == "Troll") {
        player = make_unique<Troll>(row,col);
        player->setRace("Troll");
    }
       
    floor.setChar(row,col,'@');
}

bool Level::inChamber(int row, int col, vector<vector<int>>& chamber)  {
    for (int i = 0; i < chamber.size(); ++i) {
        vector<int> temp = chamber[i];
        int tempRow = temp[0];
        int tempCol = temp[1];
        if (row == tempRow && col == tempCol) {
            return true;
        }
    }
    return false;
}

unique_ptr<Player> Level::getPlayer() {
    return std::move(player);
}

void Level::generatePotion() {


    for (int i = 0; i < 10; i++) {

        vector<int> location = randomCoordinates();
        int row = location[0];
        int col = location[1];

        int val = randomNumberGenerater(1, 6);

        // cout << "row: " << row << " col: " << col << endl;

        unique_ptr<Potion> temp;

        if (val == 1) {
            temp = make_unique<Potion>(row, col, 10, "RH");
        } else if (val == 2){
            temp = make_unique<Potion>(row, col, -10, "PH");
        } else if (val == 3){
            temp = make_unique<Potion>(row, col, 5, "BA");
        } else if (val == 4){
            temp = make_unique<Potion>(row, col, -5, "WA");
        } else if (val == 5){
            temp = make_unique<Potion>(row, col, 5, "BD");
        } else {  //  val == 6
            temp = make_unique<Potion>(row, col, -5, "WD");
        }

        potions.push_back(std::move(temp));
    }
    
}

vector<unique_ptr<Potion> > Level::getPotions() {
    return (std::move(potions));
}

void Level::generateEnemies() {
    // PRNG prng1;
    // uint32_t seed = getpid();
    // prng1.seed(seed);   

    for (int i = 0; i < 20; i++) {
        vector<int> location = randomCoordinates();
        int row = location[0];
        int col = location[1];


        int value = randomNumberGenerater(1,18);
  //      std::cout<<value<<endl;
        unique_ptr<Enemies> tmp;

        if (1 <= value && value <= 4) {
            tmp = make_unique<Human>(row,col);
        } else if (4 < value && value <= 7) {
            tmp = make_unique<Dwarf>(row,col);
        } else if ( 7 < value && value <= 12) {
            tmp = make_unique<Halfing>(row,col);
        }else if (12 <value && value <= 14) {
            tmp = make_unique<Elf>(row,col);
        } else if (14 < value && value <= 16) {
            tmp = make_unique<Orcs>(row,col);
        } else if ( 16 < value && value <= 18) {
            tmp = make_unique<Merchant>(row,col);
        }
        enemies.push_back(std::move(tmp));
    }
}


std::vector<unique_ptr<Enemies>> Level::getEnemies() {
    return (std::move(enemies));
 }

void Level::generateTreasure() {

    //std::cout<<"hello"<<endl;

    for (int i = 0; i < 10; i++) {
        vector<int> location = randomCoordinates();
        int row = location[0];
        int col = location[1];

        int value = randomNumberGenerater(1,8);
    
        unique_ptr<Treasure> tmp;

        if (1 <= value && value <= 5) {
            tmp = make_unique<Normal>(row, col);
        } else if (5 < value && value <= 6) {
            tmp = make_unique<DragonHoard>(row, col);
        } else if (6 < value && value <= 8) {
            tmp = make_unique<Small>(row, col);
        }
        treasure.push_back(std::move(tmp)); 
       // cout << "size: " << treasure.size() << endl;
    }
}



vector<unique_ptr<Treasure>> Level::getTreasure() {
    return (std::move(treasure));
}


// void Level::generatePlayers() {}
Level::~Level() {}

