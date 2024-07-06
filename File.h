#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "MainCharacter.h"

class File {
  public:
    void saveData(string password, MainCharacter& mc);
    MainCharacter login();
    MainCharacter getData(string name, string password);
};



#endif // FILE_H_INCLUDED
