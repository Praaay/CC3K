#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>


class Floor{

  std::vector<std::vector<char> > floormap;
  //char prev;

  public:
    void generateFloor();
    void printFloor();
    char charAt(int x , int y);
    void setChar(int x , int y, char tmp);

};



#endif
