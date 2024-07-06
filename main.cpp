#include <windows.h>
#include <iostream>
#include "Monster.h"
#include "MainCharacter.h"
#include "Onsen.h"
#include "File.h"
#include <unistd.h>

using namespace std;

static Onsen onsen;
static File file;

class Slime:public Monster {
public:
   Slime():Monster{"Slime", 3, 4, 3, 2, 3}{}
};

class Chimera:public Monster {
public:
   Chimera():Monster{"Chimera", 6, 5, 4, 4, 6}{}
};

class Ghost:public Monster {
public:
   Ghost():Monster{"Ghost", 9, 7, 6, 6, 9}{}
};

class KingSlime:public Monster {
public:
   KingSlime():Monster{"KingSlime", 20, 10, 8, 8, 12}{}
};

class Dragon:public Monster {
public:
   Dragon():Monster{"Dragon", 70, 20, 10, 20, 20}{}
};

Monster selectMonster() {
  int command =0;
  cout << "****************************************************************" << endl;
  cout << "Select a monster \n  Slime:1 \n  Chimera: 2 \n  Ghost: 3 \n  KingSlime: 4 \n  Dragon: 5 \n"<< endl;
  cout << "****************************************************************" << endl;
  cin >> command;
   switch(command) {
      case 1: {
        return Slime();
        break;
      }
      case 2: {
        return Chimera();
        break;
      }
      case 3: {
        return Ghost();
        break;
      }
      case 4: {
        return KingSlime();
        break;
      }
      case 5: {
        return Dragon();
        break;
      }
      default: {
        return Slime();
        break;
      }
  }
}
void fight(MainCharacter &c, Monster &m) {
  int command =0;
  bool isContinue = true;
  while(isContinue) {
    cout << "****************************************************************" << endl;
    cout << "Your HP is " <<  c.showCurrentHp() << " \nSelect a command \n   Attack: 1 \n   Escape: 2"  << endl;
    cout << "****************************************************************" << endl;
    cin >> command;
    std::system("cls");
    sleep(1);
    switch(command) {
      case 1: {
        c.attack(m);
        break;
      }
      case 2: {
        isContinue = false;
        cout << c.getName() << " escaped" << endl;
        break;
      }
      default:
        break;
    }
    if (!isContinue) {
      break;
    }

    if (m.isLose()) {
        c.winFight(m.giveExp(), m.getMoney());
        break;
    }
    m.attack(c);
    if (c.isLose()) {
        c.loseFight();
        break;
    }
  }
}


void mainMenu(MainCharacter& mc) {
  int command = 0;
  bool isContinue = true;
  while(isContinue) {
    sleep(1);
    std::system("cls");
    cout << "****************************************************************" << endl;
    cout << "Select a command \n  Fight:1 \n  Check status: 2 \n  Go to Onsen: 3 \n  Save: 9"<< endl;
    cout << "****************************************************************" << endl;
    cin >> command;
    //Execute select command
    switch(command) {
      case 1: {
        Monster m = selectMonster();
        fight(mc,m);
        break;
      }
      case 2: {
         mc.checkStatus();
         sleep(1);
         break;
      }
      case 3: {
        onsen.useFacility(mc);
        break;
      }
      case 9: {
        string password;
        cout << "Enter the password"<< endl;
        cin >> password;
        file.saveData(password, mc);
        isContinue = false;
        cout << "Thank you for playing!!" << endl;
        break;
      }
      default: {
        break;
      }

    }
  }
}


int main() {
  MainCharacter mc = file.login();
  mainMenu(mc);
  return 0;
}

