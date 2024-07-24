#ifndef POTION_H
#define POTION_H

#include <string>

using namespace std;

class Potion {
    int val;
    string type;
    int row, col;
  public:
    Potion(int row, int col, int value, string type);

};



#endif

