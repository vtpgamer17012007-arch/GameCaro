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
	int X, Y, opt; // tọa độ x, y trên màn hình và opt = 1 nếu là X, opt = -1 nếu là O
};

int get_score(int a[], int winStreak);
bool valid(int x, int y); // tọa độ có hợp lệ hay không
int evaluation(int winStreak);
void startGame(bool isNewGame, int XX, int YY, string name1, string name2, vector<pair<int, int>> Data, string fileName, int Xscore, int Oscore, int winStreak);

#endif