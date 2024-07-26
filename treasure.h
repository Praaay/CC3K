#ifndef TREASURE_H
#define TREASURE_H

#include <string>

class Treasure {

    protected:

    int value;
    std::string goldType;
    int row;
    int col;

    public:

    Treasure(int row, int col);

    int getRow();
    int getCol();
    int getValue();
    std::string getGoldType();
    void setGoldType(std::string goldType);
    void setValue(int value); 
    virtual bool checklocked();
    virtual void setlocked();
};

#endif
