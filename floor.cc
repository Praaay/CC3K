#include "floor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void Floor::generateFloor(){

    floormap.clear();
    reference.clear();
    
    std::string line;
    std::ifstream inp("blankmap.txt");

    while(getline(inp, line)){
        std::vector<char> eachline;
        for(int i = 0; i < line.length(); i++){
            eachline.push_back(line[i]);
        }
        floormap.push_back(eachline);
        reference.push_back(eachline);
    }
  //  prev = charAt(3,5);
  

   // setChar(4,5,'@');
}

void Floor::printFloor(){

    for(int i = 0; i < floormap.size(); i++){
        for(int j = 0; j < floormap[0].size(); j++){
            std::cout << floormap[i][j];
        }
        std::cout << endl;
    }
}

char Floor::referenceCharAt(int x , int y) {
    return reference[x][y];
}

char Floor::charAt(int x , int y) {
    return floormap[x][y];
}

void Floor::setChar(int x , int y ,char tmp) {
   // prev = charAt(x,y);
    // cout<<"The prev char from floor is"<<prev;<<" "
    floormap[x][y] = tmp;
}

// void Floor::clearPlayer(int x , int y,char prev) {
//     floormap[x][y] = prev;
// }