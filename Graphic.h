#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include "library.h"
#include "Console.h"
using namespace std;

void drawA(int XX, int YY);
void drawB(int XX, int YY);
void drawC(int XX, int YY);
void drawO(int XX, int YY, int co_txt);
void drawR(int XX, int YY);
void drawU(int XX, int YY);
void drawT(int XX, int YY);
void drawL(int XX, int YY);
void drawL(int XX, int YY);
void drawD(int XX, int YY);
void drawG(int XX, int YY);
void drawM(int XX, int YY);
void drawE(int XX, int YY);
void drawN(int XX, int YY);
void drawW(int XX, int YY);
void drawH(int XX, int YY);
void drawP(int XX, int YY);
void drawV(int XX, int YY);
void drawX(int XX, int YY, int co_txt);
void drawI(int XX, int YY);

void drawCARO(int XX, int YY);
void drawTHONG_TIN(int XX, int YY);
void drawCHOI_TIEP(int XX, int YY);
void drawGAME_MOI(int XX, int YY);
void drawCHONAVATAR(int XX, int YY);
void drawHUONG_DAN(int XX, int YY);
void drawGIAO_DAU(int XX, int YY);
void drawX_WIN(int XX, int YY);
void drawO_WIN(int XX, int YY);
void drawDRAW(int XX, int YY);

void drawAvatarFrame(int XX, int YY, int color);
void drawAvatar1(int XX, int YY);
void drawAvatar2(int XX, int YY);
void drawAvatar3(int XX, int YY);
void drawAvatar(int XX, int YY, int avatarID, int color);
int selectAvatar(int XX, int YY, string playerName);
void drawBoard(int Xi, int Yi, string name1, string name2, int avatarP1, int avatarP2, int Xscore, int Oscore, string fileName);
void drawBoardMenu(int XX, int YY, int size, int b_color, string str);
void drawPopUp(int XX, int YY, int h, int w);
void drawName_Board(int XX, int YY, string fileName);
void drawStatus(int XX, int YY, int opt);
int help(int XX, int YY, int locate); // bien locate de xac dinh huong dan o menu (1) hay huong dan o newgame (0)
#endif