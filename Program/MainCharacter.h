#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED
#include <string>
#include "Character.h"
#include "Monster.h"

#include <vector>
class MainCharacter: public Character {
private:
  int counterToNextLevel= 3;
  int level = 1;
  int maxHp;
public:
  MainCharacter();
  MainCharacter(string name, int level, int maxHp, int hp, int power, int defence, int money);
  int showCurrentHp();
  void checkStatus();
  void winFight(int exp, int money);
  void loseFight();
  void spendMoney(int spentMoeny);
  void heal();
  int getMaxHp();
  int getLevel();



};
#endif // MAINCHARACTER_H_INCLUDED
