#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
#include "Newgame.h"
#include "LoadGame.h"

#define co_theme 15, 0
using namespace std;

/*-----------------------@- MENU ABOUT -@-------------------------------------*/
void about(int Xi, int Yi) {
	system("cls"); 
	drawTHONG_TIN(Xi - 22, Yi - 9); 
	int XX = Xi - 6, YY = Yi + 1;

	drawPopUp(XX - 28, YY - 2, 25, 90);
	gotoXY(XX + 4, YY);      cout << "HCMUS - 25CTT3 - Group 9";
	gotoXY(XX + 4, YY + 1); cout << "GVHD: Truong Toan Thinh";

	setColor(14, 0);
	gotoXY(XX + 6, YY + 20); cout << "<< Nhan ESC de thoat >>";
	setColor(co_theme);

	Xi = 29, Yi = 13;
	setColor(co_theme);
	gotoXY(XX + 16, YY + 5);cout << "Thanh vien:";
	gotoXY(XX, YY + 7);	cout << "1. Vo Thien Phuc            - 25120222";
	gotoXY(XX, YY + 8); cout << "2. Tran Trung Hau           - 25120188";
	gotoXY(XX, YY + 9); cout << "3. Vo Ngoc Anh Linh         - 25120202";
	gotoXY(XX, YY + 10);cout << "4. Van Quoc Thinh           - 25120236";
	gotoXY(XX, YY + 11);cout << "5. Tran Anh Nhu             - 25120216";
	gotoXY(XX, YY + 12);cout << "6. Tran Nguyen Tan Phat     - 25120218";


	while (nextMove() != 5);

}

/*-----------------------@- MENU EXIT -@-------------------------------------*/
void exit() {
	system("cls");
	exit(0);
}

void drawMenu(int XX, int YY) {
	struct _aboutMenu {

		int X, Y, size, b_color;
		string str;

		void draw() {
			drawBoardMenu(X, Y, size, b_color, str);
		}
	};

	_aboutMenu s1[5], s2[5];  // s1: khong chon  ;  s2: chon
	s1[0] = { XX, YY, 20, 15,     "     CHOI MOI     " };
	s1[1] = { XX, YY + 3, 20, 15, "     CHOI TIEP    " };
	s1[2] = { XX, YY + 6, 20, 15, "     GIOI THIEU   " };
	s1[3] = { XX, YY + 9, 20, 15, "     HUONG DAN    " };
	s1[4] = { XX, YY + 12, 20, 15,"      THOAT       " };

	s2[0] = { XX, YY, 20, 14,     ">>   CHOI MOI   <<" };
	s2[1] = { XX, YY + 3, 20, 14, ">>   CHOI TIEP  <<" };
	s2[2] = { XX, YY + 6, 20, 14, ">>   GIOI THIEU <<" };
	s2[3] = { XX, YY + 9, 20, 14, ">>   HUONG DAN  <<" };
	s2[4] = { XX, YY + 12, 20, 14,">>    THOAT     <<" };

	pullList();  
	int S = 0;   // con tro menu

	while (true) {
		/*------------------ DECOR ---------------------------*/
		drawCARO(XX - 6, YY - 9);
		for (int i = 0; i < 5; ++i)
			s1[i].draw();
		s2[S].draw();

		/*----------------------------------------------------*/

		ShowCur(0);
		int _in = nextMove();

		/*----------------- Menu selection -------------------*/
		if (_in == 1 || _in == 11) S = (S + 4) % 5;        // Up
		else if (_in == 3 || _in == 33) S = (S + 1) % 5;   // Down
		else if (_in == 0) {				  // Enter
			if (S == 0) newGame(XX, YY);
			else if (S == 1) loadGame(XX, YY);
			else if (S == 2) about(XX, YY);
			else if (S == 3) help(XX, YY, 1);
			else if (S == 4) exit();
			else assert(false);
			system("cls");
		}
		/*----------------------------------------------------*/
	}
}

int main() {
	system("chcp 437");
	system("cls");
	fixConsoleWindow(140, 45);						  
	SetConsoleTitle(L"GameCaro - 25CTT3 - Group 9");  
	ShowCur(0);
	drawMenu(61, 12);

	return 0;
}


