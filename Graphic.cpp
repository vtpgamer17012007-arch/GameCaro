#include "Graphic.h"
#include "GameControl.h"
#define co_theme 15,0
const int BOARD_SIZE = 15;
using namespace std;

extern _Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];
void drawA(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawB(int XX, int YY) { // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawC(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme);
	cout << char(201);
	for (int i = 1; i <= 4; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0);  cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawO(int XX, int YY, int co_txt = 0) { // 6 * 9
	gotoXY(XX + 1, YY);
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(205) << char(205) << char(205);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186) << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186) << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
	setColor(co_theme);
}

void drawR(int XX, int YY) { // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawU(int XX, int YY) { // 6 * 9
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawT(int XX, int YY) { // 6 * 9
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawL(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	for (int i = 1; i <= 3; ++i) {
		gotoXY(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawD(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	for (int i = 2; i <= 3; ++i) {
		gotoXY(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186) << "  ";
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawG(int XX, int YY) {  // 6 * 9
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawM(int XX, int YY) {  // 6 * 11
	gotoXY(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << char(200);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(188);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " " << char(200) << char(205) << char(188) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "     " << char(200) << char(205) << char(188);
}

void drawE(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205) << char(188);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawN(int XX, int YY) {  // 6 * 10
	gotoXY(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(187) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << char(200);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " " << char(200);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200);
	for (int i = 0; i < 3; ++i) cout << char(205);
	cout << char(188);
}

void drawW(int XX, int YY) {  // 6 * 10
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " ";
	setColor(0, 0); cout << " ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(co_theme); cout << char(200);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(188);
}

void drawH(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawP(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205) << char(205) << char(188);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawV(int XX, int YY) {
	for (int i = 0; i <= 1; i++) {
		gotoXY(XX, YY + i);
		setColor(0, 0);     cout << "  ";
		setColor(co_theme); cout << char(186);

		gotoXY(XX + 4, YY + i);
		setColor(0, 0);     cout << "  ";
		setColor(co_theme); cout << char(186);

		if (i == 0) {
			gotoXY(XX + 2, YY); cout << char(187);
			gotoXY(XX + 6, YY); cout << char(187);
		}
	}

	gotoXY(XX, YY + 2);
	setColor(0, 0);     cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX + 4, YY + 2);
	setColor(0, 0);     cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX + 1, YY + 3);
	setColor(0, 0);     cout << "    ";
	setColor(co_theme); cout << char(188);

	gotoXY(XX + 2, YY + 4);
	setColor(0, 0);     cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX + 2, YY + 5);
	setColor(co_theme);
	cout << char(200);
	cout << char(205);
	cout << char(188);
}

void drawX(int XX, int YY, int co_txt = 0) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187) << "  ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(188);

	gotoXY(XX, YY + 2);
	cout << " " << char(200);
	setColor(co_txt, 0); cout << "   ";
	setColor(15, co_txt); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	cout << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(188) << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
	setColor(co_theme);
}

void drawI(int XX, int YY) {  // 6 * 3
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawCARO(int XX, int YY) {
	drawC(XX, YY);
	drawA(XX + 8, YY);
	drawR(XX + 16, YY);
	drawO(XX + 24, YY);
}

void drawTHONG_TIN(int XX, int YY) {
	drawG(XX, YY);
	drawI(XX + 9, YY);
	drawO(XX + 12, YY);
	drawI(XX + 21, YY);

	drawT(XX + 29, YY);
	drawH(XX + 38, YY);
	drawI(XX + 46, YY);
	drawE(XX + 49, YY);
	drawU(XX + 57, YY);
}

void drawCHOI_TIEP(int XX, int YY) {
	drawC(XX, YY);
	drawH(XX + 8, YY);
	drawO(XX + 16, YY);
	drawI(XX + 25, YY);
	drawT(XX + 32, YY);
	drawI(XX + 41, YY);
	drawE(XX + 44, YY);
	drawP(XX + 52, YY);
}

void drawGAME_MOI(int XX, int YY) {

	drawG(XX, YY);
	drawA(XX + 9, YY);
	drawM(XX + 17, YY);
	drawE(XX + 28, YY);

	drawM(XX + 40, YY);
	drawO(XX + 51, YY);
	drawI(XX + 60, YY);
}
void drawCHONAVATAR(int XX, int YY) {
	drawC(XX, YY);
	drawH(XX + 9, YY);
	drawO(XX + 17, YY);
	drawN(XX + 26, YY);

	drawA(XX + 42, YY);
	drawV(XX + 50, YY);
	drawA(XX + 58, YY);
	drawT(XX + 66, YY);
	drawA(XX + 75, YY);
	drawR(XX + 84, YY);
}
void drawHUONG_DAN(int XX, int YY) {
	drawH(XX, YY);
	drawU(XX + 8, YY);
	drawO(XX + 17, YY);
	drawN(XX + 26, YY);
	drawG(XX + 36, YY);

	drawD(XX + 48, YY);
	drawA(XX + 56, YY);
	drawN(XX + 64, YY);
}

void drawGIAO_DAU(int XX, int YY) {
	drawG(XX + 1, YY);
	drawI(XX + 10, YY);
	drawA(XX + 13, YY);
	drawO(XX + 21, YY);
	drawD(XX + 34, YY);
	drawA(XX + 42, YY);
	drawU(XX + 50, YY);
}

void drawX_WIN(int XX, int YY) {
	drawX(XX, YY, 4);
	drawW(XX + 12, YY);
	drawI(XX + 22, YY);
	drawN(XX + 25, YY);
}

void drawO_WIN(int XX, int YY) {
	drawO(XX, YY, 1);
	drawW(XX + 13, YY);
	drawI(XX + 23, YY);
	drawN(XX + 26, YY);
}

void drawDRAW(int XX, int YY) {
	drawD(XX, YY);
	drawR(XX + 8, YY);
	drawA(XX + 16, YY);
	drawW(XX + 24, YY);
}

void drawBoardMenu(int XX, int YY, int size, int b_color, string str = "") { // 3 * size, Menu Board
	setColor(co_theme);

	gotoXY(XX, YY); cout << char(201);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(187);

	gotoXY(XX, YY + 1); cout << char(186);
	gotoXY(XX + size - 1, YY + 1); cout << char(186);

	gotoXY(XX, YY + 2); cout << char(200);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX + 1, YY + 1);
	setColor(b_color, 0);  cout << str;
	setColor(co_theme);
}

void drawAvatarFrame(int XX, int YY, int color) {//vẽ khung cho avatar
	setColor(color, 0);
	gotoXY(XX, YY);
	cout << char(201);
	for (int i = 0; i < 7; i++) cout << char(205);
	cout << char(187);

	for (int i = 1; i <= 4; i++) {
		gotoXY(XX, YY + i);
		cout << char(186);
		gotoXY(XX + 8, YY + i);
		cout << char(186);
	}

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 7; i++) cout << char(205);
	cout << char(188);

	setColor(co_theme);
}
void drawAvatar1(int XX, int YY) {
	setColor(15, 11); // Nen mac dinh mau trang, ki tu ve ra co mau xanh
	gotoXY(XX + 2, YY + 1); cout << " o o ";
	gotoXY(XX + 3, YY + 2); cout << " | ";
	gotoXY(XX + 2, YY + 3); cout << "\\___/";
}
void drawAvatar2(int XX, int YY) {
	setColor(15, 11);
	gotoXY(XX + 2, YY + 1); cout << " > < ";
	gotoXY(XX + 3, YY + 2); cout << " v ";
	gotoXY(XX + 2, YY + 3); cout << "(___)";
}
void drawAvatar3(int XX, int YY) {
	setColor(15, 11);
	gotoXY(XX + 2, YY + 1); cout << " . . ";
	gotoXY(XX + 3, YY + 2); cout << " ~ ";
	gotoXY(XX + 2, YY + 3); cout << " \\-/ ";
}
void drawAvatar(int XX, int YY, int avatarID, int color) {
	setColor(15, 15); // Nen mac dinh
	for (int i = 1; i <= 4; i++) {
		gotoXY(XX + 1, YY + i);
		cout << "       ";
	}

	switch (avatarID) {
	case 1:
		drawAvatar1(XX, YY);
		break;
	case 2:
		drawAvatar2(XX, YY);
		break;
	case 3:
		drawAvatar3(XX, YY);
		break;
	default: // Mac dinh la avatar 1
		drawAvatar1(XX, YY);
		break;
	}
	setColor(co_theme);
}



void drawBoard(int Xi, int Yi, string name1, string name2, int avatarP1, int avatarP2, int Xscore, int Oscore, string fileName) {
	setColor(co_theme);
	drawGIAO_DAU(Xi - 25, Yi - 9);

	int XX = Xi - 25, YY = Yi - 2;
	for (int y = 0; y <= 2 * BOARD_SIZE; ++y) {
		for (int x = -20; x <= 4 * BOARD_SIZE; ++x) {
			gotoXY(XX + x, YY + y);

			if (x == -20 && y == 0) cout << char(201);
			else if (x == -20 && y == BOARD_SIZE) cout << char(200);
			else if (x == -20 && y < BOARD_SIZE) cout << char(186);
			else if (x == 4 * BOARD_SIZE + 20 && y == BOARD_SIZE) cout << char(186);
			else if (x == 0 && y == 0) cout << char(203);
			else if (x < 4 * BOARD_SIZE && y == 0) cout << char(205);
			else if (x == 0 && y == BOARD_SIZE) cout << char(185);
			else if (x == 4 * BOARD_SIZE && y == 0) { cout << char(203); for (int i = 0; i < 20; ++i) cout << char(205); cout << char(187); }
			else if (x == 4 * BOARD_SIZE && y == BOARD_SIZE) { cout << char(204); for (int i = 0; i < 20; ++i) cout << char(205); cout << char(188); }
			else if (x == 0 && y < 2 * BOARD_SIZE) cout << char(186);
			else if (x < 0 && y == BOARD_SIZE) cout << char(205);
			else if (x == 0 && y == 2 * BOARD_SIZE) cout << char(200);
			else if (x >= 0 && x < 4 * BOARD_SIZE && y == 2 * BOARD_SIZE) cout << char(205);
			else if (x == 4 * BOARD_SIZE && y == 2 * BOARD_SIZE) cout << char(188);
			else if (x == 4 * BOARD_SIZE && y < 2 * BOARD_SIZE) cout << char(186);
			else if (x == 4 * BOARD_SIZE + 20 && y < BOARD_SIZE) cout << char(186);
			else if (x % 4 == 0 && y % 2 == 0 && x > 0) cout << char(197);
			else if (x % 4 == 0 && x > 0) { if (x == 0 || x == 4 * BOARD_SIZE) cout << char(186); else cout << char(179); }
			else if (y % 2 == 0 && x > 0) { if (y == 0 || y == 2 * BOARD_SIZE) cout << char(205); else cout << char(196); }
		}
		if (y > 0 && y < BOARD_SIZE) cout << "                    " << char(186);
	}


	for (int y = 1; y <= BOARD_SIZE; ++y)
		for (int x = 1; x <= BOARD_SIZE; ++x) {
			status[y][x].Y = YY + (y - 1) * 2 + 1;
			status[y][x].X = XX + (x - 1) * 4 + 2;
			status[y][x].opt = 0;
		}


	int P2_X = XX - 22;               // Bên Trái (O)
	int P1_X = XX + 4 * BOARD_SIZE + 8; // Bên Phải (X)
	int Panel_Y = YY + 2;             

	drawAvatarFrame(P2_X + 3, Panel_Y - 1, 14); // Khung Vàng
	drawAvatar(P2_X + 3, Panel_Y - 1, avatarP2, 15);
	gotoXY(P2_X + 13, Panel_Y + 2); cout << "Score: " << Oscore;

	setColor(15, 0);
	int name2Len = name2.length();
	gotoXY(P2_X + 8 - (name2Len / 2), Panel_Y + 5);
	cout << name2;

	drawAvatarFrame(P1_X + 4, Panel_Y - 1, 14);
	drawAvatar(P1_X + 4, Panel_Y - 1, avatarP1, 15);
	gotoXY(P1_X - 6, Panel_Y + 2); cout << "Score: " << Xscore;
	setColor(15, 0);
	int name1Len = (int)name1.length();
	gotoXY(P1_X + 8 - (name1Len / 2), Panel_Y + 5);
	cout << name1;


	// Footer
	drawName_Board(XX + 4 * BOARD_SIZE - 5, YY + 2 * BOARD_SIZE + 1, fileName);
	drawStatus(XX - 7, YY + 2 * BOARD_SIZE + 1, 1);
}




void drawStatus(int XX, int YY, int opt) {	// Draw status in Caro Board
	gotoXY(XX - 3, YY);
	if (opt == 1) {
		setColor(11, 0); cout << ">> Dang choi";
		setColor(15, 0); cout << "    | 'I'- Luu  | 'U'- Hoan tac  | 'Esc'- Thoat  |  ";
		ShowCur(1);
	}

	if (opt == 2) {
		setColor(11, 0);  cout << ">> Ten File:";
		setColor(15, 0);  cout << "                                                 ";
		ShowCur(1);
	}

	if (opt == 3) {
		setColor(11, 0);
		cout << ">> File da ton tai, Ban co muon thay the no khong? Nhan Y/N";
		ShowCur(0);
	}

	if (opt == 4) {
		setColor(11, 0);
		cout << ">> Ban dang muon thoat? Nhan Y/N (Nho luu game lai game cua ban) ";
		ShowCur(0);
	} setColor(15, 0);
}

void drawName_Board(int XX, int YY, string fileName) {	// NameBoard frame
	gotoXY(XX, YY);
	setColor(0, 15);  cout << " BAN CO: ";
	if ((int)fileName.size() == 0) fileName = "[chua co]";
	while ((int)fileName.size() <= 10) fileName.push_back(' ');
	cout << fileName;
	setColor(15, 0);
}

void drawPopUp(int XX, int YY, int h, int w) {			// Pop Up Board
	setColor(co_theme);

	gotoXY(XX + 2, YY);
	cout << char(201);
	for (int i = 0; i < w - 6; ++i) cout << char(205);
	cout << char(187);

	gotoXY(XX + 1, YY + 1); cout << char(201) << char(188);
	for (int i = 2; i < w - 4; ++i) cout << " ";
	cout << char(200) << char(187);

	gotoXY(XX, YY + 2); cout << char(201) << char(188);
	for (int i = 3; i < w - 1; ++i) cout << " ";
	cout << char(200) << char(187);

	for (int i = 0; i < h - 6; ++i) {
		gotoXY(XX, YY + 3 + i); cout << char(186);
		for (int j = 1; j < w - 1; ++j) cout << " ";
		cout << char(186);
	}

	gotoXY(XX, YY + h - 3); cout << char(200) << char(187);
	for (int i = 3; i < w - 1; ++i) cout << " ";
	cout << char(201) << char(188);

	gotoXY(XX + 1, YY + h - 2); cout << char(200) << char(187);
	for (int i = 2; i < w - 4; ++i) cout << " ";
	cout << char(201) << char(188);

	gotoXY(XX + 2, YY + h - 1);
	cout << char(200);
	for (int i = 0; i < w - 6; ++i) cout << char(205);
	cout << char(188);
}

int help(int Xi, int Yi, int locate) {
	system("cls");
	drawHUONG_DAN(Xi - 24, Yi - 9);

	int XX = Xi - 27, YY = Yi - 1;
	int h = 15, w = 76;

	drawPopUp(XX, YY, h, w + 5);
	setColor(co_theme);
	for (int i = 1; i < h - 1; ++i) {
		gotoXY(XX + 41, YY + i);
		cout << "|";
	}
	setColor(11, 0);
	gotoXY(XX + 12, YY + 1);
	cout << "HUONG DAN BAN PHIM";

	gotoXY(XX + 59, YY + 1);
	cout << "LUAT";

	setColor(co_theme);
	gotoXY(XX + 12, YY + 3);
	cout << "   Nguoi choi 1|Nguoi choi 2";
	gotoXY(XX + 3, YY + 4);
	cout << "Di Len     :     W           " << char(30);
	gotoXY(XX + 3, YY + 5);
	cout << "Di qua trai:     A           " << char(17);
	gotoXY(XX + 3, YY + 6);
	cout << "Di xuong   :     S           " << char(31);
	gotoXY(XX + 3, YY + 7);
	cout << "Di qua phai:     D           " << char(16);
	gotoXY(XX + 3, YY + 8);
	cout << "Danh dau   :   Space       Enter";
	gotoXY(XX + 6, YY + 10);
	cout << "              Khac";
	gotoXY(XX + 3, YY + 11);
	cout << "  Hoan tac: U   Luu: I   Thoat: Esc";

	gotoXY(XX + 44, YY + 3);
	cout << "  Nguoi choi theo luot luan phien";
	gotoXY(XX + 44, YY + 4);
	cout << "nhau danh cac con dau vao o trong, ";
	gotoXY(XX + 44, YY + 5);
	cout << "Nguoi choi X di truoc. Nguoi thang ";
	gotoXY(XX + 44, YY + 6);
	cout << "la nguoi dau tien ghi duoc lien 5 ";
	gotoXY(XX + 44, YY + 7);
	cout << "dau theo hang ngang, hang doc, hang ";
	gotoXY(XX + 44, YY + 8);
	cout << "nghieng ma khong bi cat ngang. Neu";
	gotoXY(XX + 44, YY + 9);
	cout << "bang day ma khong ai co the lam 1 ";
	gotoXY(XX + 44, YY + 10);
	cout << "hang 5 dau thi game se hoa";
	gotoXY(XX + 44, YY + 11);

	setColor(14, 0);

	if (locate == 1) {
		gotoXY(XX + 27, YY + 13);
		cout << "<< Bam Esc de thoat >>";
		setColor(co_theme);
		while (nextMove() != 5);
	}
	else {
		gotoXY(XX + 12, YY + 13);
		cout << "<< Bam Enter de tiep tuc || Bam Esc de tro lai nhap ten>>";
		setColor(co_theme);
		char ch = _getch();
		while (ch != 13 || ch != 27) {
			if (ch == 13) return 1;		// Nhan "enter" de tiep tuc choi
			else return 0;		// Nhan "ESC" de quay ve nhap ten
		}
	}
	return 0;
}
