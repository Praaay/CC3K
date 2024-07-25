#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>


class Floor{

  std::vector<std::vector<char> > floormap;
  std::vector<std::vector<char> > reference;
  public:
    void generateFloor();
    void printFloor();
    char charAt(int x , int y);
    char referenceCharAt(int x , int y);
    void setChar(int x , int y, char tmp);
 //   void clearPlayer(int x , int y,char prev);
};



#endif

