#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Floor{

    std::vector<std::vector<char> > floormap;

  public:
    void generateFloor();
    void printFloor();

};



#endif
