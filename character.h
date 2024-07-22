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

    public: 
    virtual void move(std::string direction) = 0;
    virtual void gg() = 0;
    virtual ~Character();
};

#endif

