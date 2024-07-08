#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include <string>
#include "Character.h"

using namespace std;

class Monster:public Character{
 private:
   int exp;
 public:
   Monster(string name, int hp, int power, int defence, int exp, int money=0);
   int giveExp();
};

#endif // MONSTER_H_INCLUDED
