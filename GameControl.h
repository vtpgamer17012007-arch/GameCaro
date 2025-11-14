#ifndef _GAMECONTROL_H_
#define _GAMECONTROL_H_
#include "library.h"
#include "Newgame.h"
#include "Graphic.h"
#include "Console.h"
#include "LoadGame.h"
using namespace std;

struct _Point
{
	int X, Y, opt; // tọa độ x, y trên màn hình và opt = 1 nếu là x, opt = -1 nếu là o
};

int get_score(int a[]);
bool valid(int x, int y); // tọa độ có hợp lệ hay không
int evaluation();
void startGame(bool isNewGame, int XX, int YY, string name1, string name2, int avatarP1, int avatarP2, vector<pair<int, int>> Data, string fileName, int Xscore, int Oscore);
#endif