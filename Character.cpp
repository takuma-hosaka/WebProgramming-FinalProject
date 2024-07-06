#include "Character.h"
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;

Character::Character(){}

void Character::attack(Character &c) {
     cout << name << " attacks. " << endl;;
     sleep(1);
     int damage = power - c.defense;
     if (damage > 0) {
       cout << c.name << " gets " << damage << " damage" << endl;
       c.hp -= damage;
       if (c.hp < 0) {
       cout << c.name << " falls down." << endl;
       }
     } else {
       cout << c.name << " gets " << " No damage" << endl;
     }
     sleep(1);
  }
  bool Character::isLose() {
    return hp < 0;
  }
  string Character::getName() {
    return name;
  }

  int Character::getHp(){
    return hp;
  }
  int Character::getPower(){
    return power;
  }
  int Character::getDefense(){
    return defense;
  }
  int Character::getMoney(){
    return money;
  }

  void Character::addMoney(int money) {
    this->money += money;
  }
  void Character::subMoney(int money) {
    this->money -= money;
  }
