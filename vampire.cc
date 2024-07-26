#include "vampire.h"
#include "enemies.h"
#include "character.h"

Vampire::Vampire(int x , int y) : Player{x,y} {
    hp = 50;
    atk = 25;
    def = 25;
}

int Vampire::attack(Enemies* target) {
    int result = Player::attack(target);
    if(result != 0){
       if(target->getRace() == "Dwarf"){
           setHp(getHp() - 5);
       }
       else{
           setHp(getHp() + 5);
       }
   }
   return result;
}

Vampire::~Vampire() {}