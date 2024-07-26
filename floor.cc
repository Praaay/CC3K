#include "floor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// ASCII color codes



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

    const std::string RESET = "\033[0m";
    const std::string BLUE = "\033[38;5;45m";
    const std::string RED = "\033[38;5;196m";
    const std::string YELLOW = "\033[38;5;226m";
    const std::string GREEN = "\033[38;5;46m";

    for(int i = 0; i < floormap.size(); i++){
        for(int j = 0; j < floormap[0].size(); j++){

            if (floormap[i][j] == '@' || floormap[i][j] == '\\') {
               std::cout<<BLUE<<floormap[i][j]<<RESET;
            } else if ( floormap[i][j] == 'E' || floormap[i][j] == 'D' || floormap[i][j] == 'O' 
            || floormap[i][j] == 'M'|| floormap[i][j] == 'L' || floormap[i][j] == 'H' || floormap[i][j] == 'W') {
                std::cout<<RED<<floormap[i][j]<<RESET;
            } else if (floormap[i][j] == 'G') {
                std::cout<<YELLOW<<floormap[i][j]<<RESET;
            } else if (floormap[i][j] == 'P') {
                std::cout<<GREEN<<floormap[i][j]<<RESET;
            } else {
                std::cout<<floormap[i][j];
            }
        }
        std::cout << endl;
    }
}

char Floor::referenceCharAt(int x , int y) {
    return reference[x][y];
}
void Floor::referenceSetAt(int x, int y, char symbol){
    reference[x][y] = symbol;
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