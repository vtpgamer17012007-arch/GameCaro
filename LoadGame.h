#ifndef _LOADGAME_H_
#define _LOADGAME_H_
#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"

#define F first
#define S second
typedef pair<int, int> ii;
using namespace std;

void loadGame(int XX, int YY);
void saveGame(int XX, int YY, vector<ii> Cache, int Xscore, int Oscore, string name1, string name2, string& nameFile);
void loadFromFile(string nameFile, vector<ii>& Cache, int& Xscore, int& Oscore, string& name1, string& name2);
void deleteFile(string nameFile);
void pullList();
void pushList();

#endif
