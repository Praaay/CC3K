#ifndef ELF_H
#define ELF_H
#include "enemies.h"

class Elf : public Enemies {
    public:
     void attack(Player *) override;
     void attackedBy(Player * ) override;
     void dropGold() override;
     ~Elf();
};

#endif