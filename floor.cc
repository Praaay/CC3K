#include "floor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void floor::generatefloor(){

    std::string line;
    std::ifstream inp("blankmap.txt");

    while(getline(inp, line)){
        std::vector<char> eachline;
        for(int i = 0; i < line.length(); i++){
            eachline.push_back(line[i]);
        }
        floormap.push_back(eachline);
    }
}

void floor::printfloor(){

    for(int i = 0; i < floormap.size(); i++){
        for(int j = 0; j < floormap[0].size(); j++){
            std::cout << floormap[i][j];
        }
    }

}
