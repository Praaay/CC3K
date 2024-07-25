#ifndef ELF_H
#define ELF_H
#include "enemies.h"

class Elf : public Enemies {
    public:
     Elf(int row, int col);
     void attack(Player *) override;
     void dropGold() override;
     ~Elf();
};

#endif