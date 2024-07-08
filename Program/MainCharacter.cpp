#include "MainCharacter.h"
#include <iostream>
#include <string>
#include "Monster.h"
#include <unistd.h>

  MainCharacter::MainCharacter(){
    string mainName;
    cout << "Enter your name" << endl;
    cin >> mainName;
    name=mainName;
    hp= 10;
    maxHp = 10;
    power = 5;
    defense = 3;
    money = 10;
    cout << "Let's start adventure!!" << endl;
  }

   MainCharacter::MainCharacter(string name, int level, int maxHp, int hp, int power, int defense, int money)
   :Character{name,hp,power,defense, money},level{level},maxHp{maxHp} {}

  void MainCharacter::winFight(int exp, int money) {
     sleep(1);
     cout << name << " gets " << exp << " exp and " << money << " yen " << endl;

    this -> money += money;
    counterToNextLevel -= exp;
    if (counterToNextLevel <= 0) {
      level++;
      counterToNextLevel = level*5 + counterToNextLevel;
      maxHp += 5;
      power += 3;
      defense += 1;
      sleep(1);
      cout << "**************************************************************** \n  " << endl;
      cout << name << " becomes level " << level << "!! \n" << endl;
      checkStatus();
      cout << "****************************************************************" << endl;
    }
  }

  void MainCharacter::loseFight() {
   cout << "You lost" << endl;
   cout << "You lost a half of money" << endl;
   money = money/2;
   hp=maxHp;
   sleep(1);
  }

  int MainCharacter::showCurrentHp() {
     return hp;
  }
  void MainCharacter::checkStatus() {
     cout << "Level: " << level << " Lv" << endl;
     cout << "MaxHP: " << maxHp << endl;
     cout << "CurrentHP: " << hp << endl;
     cout << "POWER: " << power << endl;
     cout << "DEFENCE: " << power << endl;
     cout << "Money: " << money << " yen" <<  endl;
     cout <<  counterToNextLevel << " exp is necessary to level up" << endl;
  }


  void MainCharacter::spendMoney(int spentMoney) {
   money -= spentMoney;
  }
  void MainCharacter::heal() {
    hp = maxHp;
  }
  int MainCharacter::getMaxHp(){
    return maxHp;
  }
  int MainCharacter::getLevel() {
    return level;
  }


