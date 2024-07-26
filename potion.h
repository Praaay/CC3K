#ifndef POTION_H
#define POTION_H

#include <string>

using namespace std;

class Potion {
  
    string type;
    int row, col;
    int val;
  public:
    Potion(int row, int col, int value, string type);

    int getVal();
    string getType();

    int getRow();
    int getCol();

};



#endif

