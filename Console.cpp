#include "Console.h"


void fixConsoleWindow(int WIDTH, int HEIGHT) {
	system("COLOR f0");
	HWND consoleWindow = GetConsoleWindow();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD bufferSize = { (SHORT)WIDTH, (SHORT)HEIGHT };
	SetConsoleScreenBufferSize(hConsole, bufferSize);

	SMALL_RECT windowSize = { 0, 0, (SHORT)(WIDTH - 1), (SHORT)(HEIGHT - 1) };
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void gotoXY(int x, int y) {		
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int background_color, int text_color) { 
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(hconsole, color_code);
}

void draw_square(int i, int j, int x, int y, int color) {
	x = (x - 1) * 2 + 1;
	gotoXY(x + i, y + j);
	setColor(color, color);
	cout << "  ";
	setColor(15, 15);
}

void decorate_draw(int x, int y, const string& nameFile) {
	ifstream file(nameFile.c_str());
	string s;
	int i = 0;
	while (getline(file, s))
	{
		i++;
		stringstream ss(s);
		int j = 0;
		while (!ss.eof())
		{
			j++;
			int color;
			ss >> color;
			draw_square(x, y, j, i, color);
		}
	}
}

void ShowCur(bool CursorVisibility) { 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void curr_coordinate(int& x, int& y)	
{
	CONSOLE_SCREEN_BUFFER_INFO curr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curr);
	x = curr.dwCursorPosition.X;
	y = curr.dwCursorPosition.Y;
}

int nextMove() {   // 
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			if (c == 13) return 0;	            // Enter
			if (c == ' ') return 10;	        // Space
			if (c == 27) return 5;				// Exit

			if (c == -32) {						// Arrow
				c = _getch();

				if (c == 72) return 11;			// Up
				if (c == 75) return 22;			// Left
				if (c == 80) return 33;			// Down
				if (c == 77) return 44;			// Right
			}

			if (c == 'W' || c == 'w') return 1;	// Up
			if (c == 'A' || c == 'a') return 2;	// Left
			if (c == 'S' || c == 's') return 3;	// Down
			if (c == 'D' || c == 'd') return 4;	// Right

			if (c == 'U' || c == 'u') return 6;	// Undo
			if (c == 'I' || c == 'i') return 7;	// Save
		}
	}
}