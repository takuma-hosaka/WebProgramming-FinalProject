#include "MainCharacter.h"
#include "Onsen.h"
#include <iostream>
#include <unistd.h>

void Onsen::useFacility(MainCharacter& mc) {
  cout << mc.getName() << " goes1 to onsen" << endl;
  if (mc.getMoney() < 5) {
   cout << "You don't enough money to pay. Get out!!" << endl;
   sleep(1);
   return;
 }
  mc.spendMoney(5);
  mc.heal();
  cout << mc.getName() << " recovered!!" << endl;
  sleep(1);
}
