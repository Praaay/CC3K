#ifndef DWARF_H
#define DWARF_H
#include "enemies.h"

class Dwarf : public Enemies {
    public:
     void attackedBy(Player * ) override;
     void dropGold() override;
     ~Dwarf();
};

#endif