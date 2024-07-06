#include "File.h"
#include <fstream>
#include <iostream>
#include <string>

void  File::saveData(string password, MainCharacter& mc) {

  ofstream file{mc.getName()+ ".txt"};
  //1:name
  file << mc.getName() << endl;
  //2:password
  file << password << endl;
  //3:Level
  file << mc.getLevel() << endl;
  //4:MaxHp
  file << mc.getMaxHp() << endl;
  //5:CurrentHp
  file << mc.getHp() << endl;
  //6:Power
  file << mc.getPower() << endl;
  //7:Defense
  file << mc.getDefense() << endl;
  //8:Money
  file << mc.getMoney() << endl;
  file.close();
}

MainCharacter File::login() {
  int command = 0;
  cout << "****************************************************************" << endl;
  cout << "Select a command \n  Start new game:1 \n  Continue game: 2 \n"<< endl;
  cout << "****************************************************************" << endl;
  cin >> command;
  switch(command) {
    case 1: {
      MainCharacter mc;
      return mc;
      break;
    }
    case 2: {
      string name, password;
      cout << "Enter your name"<< endl;
      cin >> name;
      cout << "Enter the password"<< endl;
      cin >> password;
      return getData(name, password);
      break;
    }
    default: {
      MainCharacter mc;
      return mc;
      break;
    }

  }
}

  MainCharacter File::getData(string name,string password) {
  ifstream iFile{name+ ".txt"};

  string s;
   getline(iFile, s);
   string n =s;
   getline(iFile, s);
   string p=s;
   getline(iFile, s);
   int l=stoi(s);
   getline(iFile, s);
   int mh = stoi(s);
   getline(iFile, s);
   int h = stoi(s);
   getline(iFile, s);
   int power = stoi(s);
   getline(iFile, s);
   int defense = stoi(s);
   getline(iFile, s);
   int money = stoi(s);

   iFile.close();

   if (password != p) {
    cout << "This password is not correct" << endl;
    return login();
   } else {
    cout << "Data was loaded successfully!!" << endl;
    return MainCharacter(n,l,mh,h,power,defense,money);
   }
}

