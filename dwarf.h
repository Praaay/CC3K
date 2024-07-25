#ifndef DWARF_H
#define DWARF_H
#include "enemies.h"

class Dwarf : public Enemies {
    public:
     Dwarf(int row, int col);
     void dropGold() override;
     ~Dwarf();
};

#endif