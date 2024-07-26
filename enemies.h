#ifndef ENEMIES_H
#define ENEMIES_H

#include "character.h"
#include "string.h"
#include "treasure.h"
class Player;

class Enemies : public Character {
    protected:
    bool hasMoved;  
    std::string race;

    public:
    Enemies(int x , int y);
    void attack(Player * player);
    
    virtual void dropGold();
    //void move(Floor floor, std::string direction) override;
    bool inRange(Player * player);
    std::string getRace();
    bool getHasMoved();
    void setHasMoved(bool newvalue);
    virtual Treasure* getassociatedDH();
  //  void gg() override;   
    virtual ~Enemies();
};

#endif