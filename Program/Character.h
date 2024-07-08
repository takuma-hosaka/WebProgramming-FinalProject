#include <string>

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

using namespace std;

class Character{
 protected:
   string name;
   int hp;
   int power;
   int defense;
   int money;

 public:
  Character();
  Character(string name, int hp, int power, int defense,int money)
  :name(name),hp(hp),power(power),defense(defense),money(money){};
  void attack(Character &c);
  bool isLose();
  string getName();
  int getHp();
  int getPower();
  int getDefense();
  int getMoney();
  void addMoney(int money);
  void subMoney(int money);
};

#endif // CHARACTER_H_INCLUDED
