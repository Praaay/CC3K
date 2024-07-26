#ifndef DWARF_H
#define DWARF_H
#include "enemies.h"

class Dwarf : public Enemies {
    public:
     Dwarf(int x , int y);
     void dropGold() override;
     ~Dwarf();
};

#endif