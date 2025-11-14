#include "LoadGame.h"
#include "GameControl.h"
#include "Newgame.h"
#include "Graphic.h"
#include "library.h"
#define co_theme 15,0 //mau sac 

const int BOARD_SIZE = 15;
vector<string> fileNames;


void loadGame(int XX, int YY) {
	struct _aboutMenu {
		int X, Y, size, b_color;
		string str;

		void draw() {
			drawBoardMenu(X, Y, size, b_color, str);
		}
	};

	/*------------------ DECOR ---------------------------*/
	int sz = min((int)fileNames.size() - 1, 14);
	_aboutMenu s1[15], s2[15];
	for (int i = 0; i < 15; ++i) {
		s1[i] = { XX - 30 + 30 * (i / 5), YY + (i % 5) * 3, 20, 12, "      TRONG       " };
		s2[i] = { XX - 30 + 30 * (i / 5), YY + (i % 5) * 3, 20, 14, "" };

		if (i <= sz) {
			string tmp = fileNames[i];
			int siz = 14 - (int)tmp.size();

			for (int j = 1; 2 * j <= siz; ++j)
				tmp = ' ' + tmp + ' ';
			if (siz & 1) tmp += ' ';

			s1[i].str = "  " + tmp + "  ";
			s2[i].str = ">>" + tmp + "<<";
			s1[i].b_color = 15;
		}
	}

	system("cls"); // lam sach man hinh
	drawCHOI_TIEP(XX - 19, YY - 9); // ve chu load game
	drawPopUp(XX - 33, YY - 1, 20, 86); // ve khung pop up 
	/*----------------------------------------------------*/

	int S = min(0, sz);		// Pointer
	while (true) {
		for (int i = 0; i < 15; ++i)
			s1[i].draw();
		if (S != -1) s2[S].draw();

		setColor(co_theme);
		gotoXY(XX - 29, YY + 15); cout << "                                                                               ";
		gotoXY(XX - 29, YY + 16); cout << "                                                                               ";
		gotoXY(XX - 29, YY + 17); cout << "                                                                               ";
		gotoXY(XX - 3, YY + 16); setColor(11, 0);
		cout << " << Bam ESC de thoat >> ";
		setColor(co_theme);

		int _in = nextMove();
		if (_in == 5) break;			// Esc
		else if (S == -1) continue;		// No files were saved

		if (_in == 0) {
			_aboutMenu s3[3], s4[3];	// s3: ko chon, s4: chon
			s3[0] = { XX - 12, YY + 15, 16, 15, "     CHOI     " };
			s3[1] = { XX + 8, YY + 15, 16, 15,  "     XOA      " };
			s3[2] = { XX + 28, YY + 15, 17, 15, "    DOI TEN    " };

			s4[0] = { XX - 12, YY + 15, 16, 14, ">>   CHOI   <<" };
			s4[1] = { XX + 8, YY + 15, 16, 14,  ">>   XOA    <<" };
			s4[2] = { XX + 28, YY + 15, 17, 14, ">>  DOI TEN  <<" };

			
			s1[S].draw();
			gotoXY(XX - 30, YY + 16); setColor(co_theme);
			cout << "                                                                                 ";
			gotoXY(XX - 24, YY + 16); setColor(11, 0); cout << " Chon: ";

			int Sj = 0;
			while (true) {
				
				gotoXY(XX - 30, YY + 16); setColor(co_theme);
				cout << "                                                                                 ";
				gotoXY(XX - 24, YY + 16); setColor(11, 0); cout << " Chon: ";

				for (int j = 0; j < 3; ++j)
					s3[j].draw();
				s4[Sj].draw();

				int _in = nextMove();
				if (_in == 5) break;					// Esc
				else if (_in == 2 || _in == 22) Sj = (Sj + 2) % 3;	// Left
				else if (_in == 4 || _in == 44) Sj = (Sj + 1) % 3;	// Right
				else if (_in == 0) {					// Enter
					if (Sj == 0) {		// Load file and play
						vector<ii> Cache;
						int Xscore, Oscore;
						string name1, name2;
						

						loadFromFile(fileNames[S], Cache, Xscore, Oscore, name1, name2);
						//startGame(false, XX, YY, name1, name2, Cache, fileNames[S], Xscore, Oscore);
						return;
					}

					if (Sj == 1) {		// Delete file
						deleteFile(fileNames[S]);
						for (int t = S + 1; t <= sz; ++t) {
							fileNames[t - 1] = fileNames[t];
							s1[t - 1].str = s1[t].str;
							s2[t - 1].str = s2[t].str;
						}

						fileNames.pop_back();
						s1[sz].str = "      TRONG       ";
						s1[sz].b_color = 12;
						s2[sz].str = "";
						--sz;  S = min(S, sz);

					}
					else {			// doi ten
						setColor(co_theme);
						gotoXY(XX - 29, YY + 15); cout << "                                                                               ";
						gotoXY(XX - 29, YY + 16); cout << "                                                                               ";
						gotoXY(XX - 29, YY + 17); cout << "                                                                               ";

						// them ten moi
					renameFile:
						string tmp;
						gotoXY(XX - 24, YY + 16); cout << " Ten Moi:                                                         ";
						if (!putname(XX - 13, YY + 16, tmp = fileNames[S])) continue;

						// kiem tra co trung ten khong
						bool checkSame = 0;
						for (int t = 0; t <= sz; ++t)
							if (t != S && fileNames[t] == tmp)
								checkSame = 1;

						if (checkSame) {
							gotoXY(XX - 24, YY + 16); cout << ">> Ten da ton tai, Ban co muon doi ten khac khong? Nhan Y/N <<";
							while (true) {
								char key = _getch();
								if (key == 'N' || key == 'n') break;
								else if (key == 'Y' || key == 'y') goto renameFile;
							} break;
						}

						// Process rename
						string old_name = fileNames[S] + ".txt";
						string new_name = tmp + ".txt";
						rename(old_name.c_str(), new_name.c_str());

						fileNames[S] = tmp;
						int siz = 14 - (int)tmp.size();

						for (int t = 1; 2 * t <= siz; ++t)
							tmp = ' ' + tmp + ' ';
						if (siz & 1) tmp += ' ';

						s1[S].str = "  " + tmp + "  ";
						s2[S].str = ">>" + tmp + "<<";
					}
					pushList();
					break;
				}
			} if (S != -1) s2[S].draw();

		}
		else {
			int col = S / 5, nxt_S;
			if (_in == 1 || _in == 11) nxt_S = (S + 4) % 5 + col * 5;		// Up
			else if (_in == 2 || _in == 22) nxt_S = (S + 10) % 15;			// Left
			else if (_in == 3 || _in == 33) nxt_S = (S + 1) % 5 + col * 5;	// Down
			else if (_in == 4 || _in == 44) nxt_S = (S + 5) % 15;			// Right
			if (nxt_S <= sz) S = nxt_S;		
		}
	}
}

void saveGame(int XX, int YY, vector<ii> Cache, int Xscore, int Oscore, string name1, string name2, string& nameFile) {
	if (nameFile == "") {
	insertName:
		drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 2);
		if (!putname(XX - 18, YY + 2 * BOARD_SIZE - 1, nameFile)) {
			drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
			return;
		} if (nameFile == "") goto insertName;
	}

	bool checkSame = 0;
	for (string tmp : fileNames)
		if (tmp == nameFile) checkSame = 1;

	if (checkSame) {
		drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 3);
		while (true) {
			char key = _getch();
			if (key == 'N' || key == 'n') {
				drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
				nameFile = "";
				return;
			}
			else if (key == 'Y' || key == 'y') break;
		}
	}
	else {
		while ((int)fileNames.size() >= 15)
			fileNames.erase(fileNames.begin());
		fileNames.push_back(nameFile);
	}

	drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);

	drawName_Board(XX + 4 * BOARD_SIZE - 30, YY + 2 * BOARD_SIZE - 1, nameFile);
	pushList();

	// Save file to PC
	ofstream File(nameFile + ".txt");
	File << Xscore << " " << Oscore << '\n';
	File << name1 << " " << name2 << '\n';

	for (const auto& tmp : Cache) {
		File << tmp.first << " " << tmp.second << "\n";
	} File.close();
}

void loadFromFile(string nameFile, vector<ii>& Cache, int& Xscore, int& Oscore, string& name1, string& name2) {
	Cache.clear();
	nameFile += ".txt";
	ifstream file(nameFile);
	int x, y;

	file >> Xscore >> Oscore >> name1 >> name2;
	while (file >> x >> y) Cache.emplace_back(x, y);
	file.close();
}

void pullList() {		
	string s; fileNames.clear();
	ifstream file("ListNameFiles.txt");
	while (file >> s) fileNames.emplace_back(s);
	file.close();
}

void pushList() {		
	ofstream File("ListNameFiles.txt");
	for (string s : fileNames) File << s << '\n';
	File.close();
}

void deleteFile(string nameFile) {	
	nameFile += ".txt";
	remove(nameFile.c_str());
}