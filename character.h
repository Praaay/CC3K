#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character {
    protected:
    int hp;
    int atk;
    int def;
    int row;
    int col;
    char symbol;

    public: 
    Character(char display, int x , int y);
    virtual void move(std::string direction);
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

