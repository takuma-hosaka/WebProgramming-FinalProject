#include "Monster.h"
#include <iostream>
#include <string>

Monster::Monster(string name, int hp, int power, int defence, int exp, int money)
  :Character{name, hp, power, defence, money},exp{exp}{
     cout << "A " << name << " appears!!" << endl;
   }
   int Monster::giveExp() {
     return exp;
   }

