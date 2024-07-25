#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "floor.h"

class Character {
    protected:
    int hp;
    int atk;
    int def;
    int row;
    int col;
    char symbol;
    std::string race;

    public: 
    Character(char display, int row , int col, int atk, int def, int hp, std::string race);

    virtual void move(Floor &floor, std::string direction, char symbol);

    int getRow();
    int getCol();

    int getAtk();
    int getDef();
    int getHp();
    void setAtk(int atk);
    void setDef(int def);
    void setHp(int hp);
    void setPosition(int row, int col);
    virtual void gg() = 0;
    virtual ~Character();
};

#endif

