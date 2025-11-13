#include "Newgame.h"
#include "GameControl.h"
using namespace std;

/*-----------------@- Function Import name -@-----------------------*/
bool putname(int XX, int YY, string& str) {   //tao o van ban de nhap ten
	const int  Xi = XX, Yi = YY;	//sz de dem do dai ten nguoi nhap
	string tmp = str;				// luu tmp la ham mac dinh
	string input = "";  //khai bao chuoi de luu ten nguoi nhap
	int vitricontro = 0; //khai bao vi tri con tro 
	bool tenmacdinh = true;

	setColor(15, 8); //mau:chu trang , nen xam
	gotoXY(Xi, Yi);// di chuyen con tro den vi tri toa do(Xi,Yi)
	cout << str;// In ten mac dinh ra man hinh
	ShowCur(true); //hien thi vi tri con tro

	while (true) {
		int ch_int = _getch();
		char ch = ch_int;

		if (ch_int == 0 || ch_int == 224) {
			ch = _getch();
			switch (ch) {
			case 75:// mui ten trai
				if (!tenmacdinh && vitricontro > 0) {// da nhap ki tu
					vitricontro--; // vi tri con tro -1
					gotoXY(Xi + vitricontro, Yi);// di chuyen con tro sang trai
				}
				break;
			case 77://mui ten phai
				if (!tenmacdinh && vitricontro < (int)input.length()) {// vi tri con tro nho hon do dai cua ten da nhap vao
					vitricontro++;// vi tri con tro +1
					gotoXY(Xi + vitricontro, Yi); // di chuyen con tro sang phai
				}
				break;
			case 83:// delete
				if (!tenmacdinh && vitricontro < (int)input.length()) {// da nhap ten va vi tri con tro nho hon do dai cua du lieu da nhap vao
					input.erase(vitricontro, 1); //xoa phia sau vi tri con tro
					gotoXY(Xi, Yi);
					cout << input << " ";
					gotoXY(Xi + vitricontro, Yi);
				}
				break;
			}
			continue;
		}
		else if (ch == 13) {// nhan nut enter
			if (tenmacdinh || input.empty()) {// neu chua nhap gi thi in ra ten mac dinh(player 1 or player2)
				str = tmp;
			}
			else { //nguoc lai thi luu ten da nhap
				str = input;
			}
			break;
		}
		else  if (ch == 27) {// neu nhan Esc thì huy bo va tra ve 0 (quay ve man hinh menu)
			ShowCur(false);
			return 0;
		}

		else if (ch == '\b') {
			if (!tenmacdinh && vitricontro > 0) { // neu da nhap ten va vi tri con tro lon hon 0
				vitricontro--; // vi tri con tro giam 1
				input.erase(vitricontro, 1);// xoa ngay truoc vi tri con tro
				gotoXY(Xi, Yi);
				cout << input << " ";
				gotoXY(Xi + vitricontro, Yi);
				if (input.empty()) {// neu da xoa het cac ki tu da nhap
					tenmacdinh = true;// quay lai trang thai ten mac dinh
					vitricontro = 0;
					setColor(15, 8);
					gotoXY(Xi, Yi);
					cout << tmp; //in ra ten mac dinh
					gotoXY(Xi, Yi);
				}
			}
		}
		else if ((isalpha((unsigned char)ch) || isdigit((unsigned char)ch)) && (tenmacdinh || input.length() < 10)) {
			if (tenmacdinh) {
				tenmacdinh = false;// danh dau da nhap ten
				input = ""; // Xoa hoan toan ten mac dinh trong bien str
				setColor(15, 0);//Dat mau
				gotoXY(Xi, Yi); //Di chuyen con tro ve dau
				cout << string(tmp.length(), ' ');//In khoang trang xoa ten mac dinh
				gotoXY(Xi, Yi);
				vitricontro = 0;// dat lai vi tri con tro
			}
			input.insert(vitricontro, 1, ch);//chen ki tu vua nhap vao vi tri con tro
			vitricontro++;// vi tri con tro +1
			gotoXY(Xi, Yi);//Di chuyen con tro den vi tri hien tai
			cout << input; // In lai toan bo chuoi
			gotoXY(Xi + vitricontro, Yi);//di chuyen con tro lai dung vi tri
		}
	}
	ShowCur(false);// an con tro khi da nhap xong
	return true; //Sau khi thoat vong lap ,tra ve 1 (true) bao hieu thanh cong.
}



void newGame(int XX, int YY) {
newgame:
	/*------------------ DECOR ---------------------------*/
	system("cls"); drawGAME_MOI(XX - 20, YY - 9);
	/*----------------------------------------------------*/

	/*----------------- Import Name  ---------------------*/
	string name1, name2;
	drawBoardMenu(XX, YY, 31, 15, " Ten nguoi choi 1: ");
	if (!putname(XX + 19, YY + 1, name1 = "[nhap_ten]")) return;   // Name of player 1

	drawBoardMenu(XX, YY + 3, 31, 15, " Ten nguoi choi 2: ");
	if (!putname(XX + 19, YY + 4, name2 = "[nhap_ten]")) return;   // Name of player 2
AvatarSelect:
	int avatarP1 = selectAvatar(XX, YY + 2, name1);

	// Kiem tra neu avatarP1 tra ve 0 (do nhan ESC)
	if (avatarP1 == 0) goto newgame; // Quay lai man hinh dat ten

	int avatarP2 = selectAvatar(XX, YY + 2, name2);
	// Kiem tra neu avatarP2 tra ve 0 (do nhan ESC)
	if (avatarP2 == 0) goto newgame; // Quay lai man hinh dat ten

	if (help(61, 12, 0) == 1) { // Neu help tra ve 1 (Nhan Enter)
		startGame(true, XX + 3, YY, name1, name2, avatarP1, avatarP2, {}, "", 0, 0);
	}
	else // Neu help tra ve 0 (Nhan ESC)
		goto AvatarSelect; // Quay lai man hinh chon avatar

	/*----------------------------------------------------*/
}
