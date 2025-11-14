#include "GameControl.h"
#include "Graphic.h"
#include "Newgame.h"
#include "LoadGame.h"
#include "library.h"
#include <iostream>

#define F first
#define S second

#define moveTo(x, y) gotoXY(status[x][y].X, status[x][y].Y)
const int BOARD_SIZE = 15;
typedef pair<int, int> ii;


int Turn, maxDepth = 3;
_Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];
vector<ii> Cache, winLine;


int consecutiveScore(int len, int openEnds, bool currentTurn) // return the score of consecutive elements
{
    if (len < 5 && openEnds == 0) return 0;
    switch (len)
    {
    case 4:
        switch (openEnds)
        {
        case 1:
            if (currentTurn)
                return 10000000;
            return 50;
        case 2:
            if (currentTurn)
                return 10000000;
            return 10000000;
        }
        break;
    case 3:
        switch (openEnds)
        {
        case 1:
            if (currentTurn)
                return 7;
            return 5;
        case 2:
            if (currentTurn)
                return 10000;
            return 50;
        }
        break;
    case 2:
        switch (openEnds)
        {
        case 1:
            return 3;
        case 2:
            return 5;
        }
        break;
    case 1:
        switch (openEnds)
        {
        case 1:
            return 1;
        case 2:
            return 2;
        }
        break;
    default:
        switch (openEnds)
        {
        case 2:
            return (int) 1e10;
        case 1:
            return (int)1e10 - (int)1e9;
        case 0:
            return (int)1e10 - (int)2e9;
        }
    }
    return 0;
}

int get_score(int a[], int player)
{
    int Size = BOARD_SIZE + 2;
    int score = 0;
    for (int i = 1; i < Size - 1; i++) if (abs(a[i]) == 1) // get consecutive equal elements 
    {
        int j = i;
        while (j + 1 < Size - 1 && a[i] == a[j + 1]) j++;

        int len = j - i + 1;
        int openEnds = 2 - (a[i - 1] != 0) - (a[j + 1] != 0); // number of open cells
        score += 1ll * consecutiveScore(len, openEnds, player == a[i]) * a[i];
        i = j;
    }
    return score;
}

bool valid(int x, int y)
{
    return y > 0 && x > 0 && x <= BOARD_SIZE && y <= BOARD_SIZE;
}

int evaluation(int player) // evaluate a status
{
    int score = 0;
    int b[BOARD_SIZE + 2];
    for (int i = 1; i <= BOARD_SIZE; i++) // get a row
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(i, k))
                b[k] = status[i][k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ i, k });
            return score;
        }
    }

    for (int j = 1; j <= BOARD_SIZE; j++) // get a column
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(k, j))
                b[k] = status[k][j].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ k, j });
            return score;
        }
    }

    for (int i = 0; i <= BOARD_SIZE; i++) // get a main diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(i + k, k))
                b[k] = status[i + k][k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ i + k, k });
            return score;
        }
    }
    for (int j = 1; j <= BOARD_SIZE; j++) // get a main diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(k, j + k))
                b[k] = status[k][j + k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ k, j + k });
            return score;
        }
    }

    for (int i = 1; i <= BOARD_SIZE + 1; i++) // get a secondary diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(i - k, k))
                b[k] = status[i - k][k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ i - k, k });
            return score;
        }
    }
    for (int j = 1; j <= BOARD_SIZE; j++) // get a secondary diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(BOARD_SIZE + 1 - k, j + k))
                b[k] = status[BOARD_SIZE + 1 - k][j + k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ BOARD_SIZE + 1 - k, j + k });
            return score;
        }
    }
    return score;
}



void makeMove(int Turn, int x, int y) // make a move
{
    status[x][y].opt = Turn;

    moveTo(x, y);

    if (Turn == 1)
    {
        setColor(15, 4);
        cout << 'X';
    }
    else if (Turn == -1)
    {
        setColor(15, 1);
        cout << 'O';
    }
    else
    {
        setColor(15, 15);
        cout << " ";
    }
    moveTo(x, y);
}


void displayWinLine() // Bold the winning line
{
#define getVal(i) status[winLine[i].F][winLine[i].S].opt

    for (int i = 0; i < (int)winLine.size(); i++)
    {
        if (abs(getVal(i)) == 1)
        {
            int j = i;
            while (j + 1 < (int)winLine.size() - 1 && getVal(i) == getVal(j + 1)) j++;
            int len = j - i + 1;
            if (len >= 5)
            {
                for (int T = 0; T < 3; T++) // 3 times
                {
                    for (int k = i; k <= j; k++)
                    {
                        if (!valid(winLine[k].F, winLine[k].S)) continue;//Đảm bảo tọa độ hợp lệ trước khi vẽ
                        int XX = status[winLine[k].F][winLine[k].S].X;
                        int YY = status[winLine[k].F][winLine[k].S].Y;
                        gotoXY(XX - 1, YY);
                        setColor(getVal(k) == 1 ? 4 : 1, 15);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(500);
                    for (int k = i; k <= j; k++)
                    {
                        int XX = status[winLine[k].F][winLine[k].S].X;
                        int YY = status[winLine[k].F][winLine[k].S].Y;
                        gotoXY(XX - 1, YY);
                        setColor(15, getVal(k) == 1 ? 4 : 1);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(300);
                }
                return;
            }
        }
    }
}

void startGame(bool isNewGame, int XX, int YY, string name1, string name2, int avatarP1, int avatarP2, vector<ii> Data, string fileName, int Xscore, int Oscore)
{
playAgain:
   
    int P1_Avatar_X = (XX - 25) + 4 * BOARD_SIZE + 7;
    int P1_Avatar_Y = (YY - 2) + 5;
    int P2_Avatar_X = (XX - 25) - 14;
    int P2_Avatar_Y = (YY - 2) + 5;

    system("cls");

    int x, y;
    Cache.clear();
    winLine.clear(); //Xóa dòng thắng của ván trước
    ShowCur(1);
    drawBoard(XX, YY, name1, name2, avatarP1, avatarP2, Xscore, Oscore, fileName);

     if (isNewGame) // if it is a new game then reset everything
        {
            Turn = 1;
            x = 8, y = 8;
            moveTo(x, y);
        }
        else { // if not, use the previous data for the game
            Turn = 1;

            for (auto tmp : Data) {
                makeMove(Turn, tmp.F, tmp.S);
                Turn *= -1;

            }

            Cache = Data;
            if (Data.empty()) x = y = 8;
            else {
                x = Data.back().F;
                y = Data.back().S;
            }
        }


        while (abs(evaluation()) < 100) // while the game is not over then keep playing
        {

            if (Turn == 1) {
                drawX(XX - 18 + 4 * BOARD_SIZE, YY + 3, 4);
                drawO(XX - 39, YY + 3, 8);
            }
            else {
                drawO(XX - 39, YY + 3, 1);
                drawX(XX - 18 + 4 * BOARD_SIZE, YY + 3, 8);
            } moveTo(x, y);



            while (true)
            {
                int Key = nextMove();
                if (Turn == 1) { // turn X - A, W, S, D
                    if (Key == 1 && x > 1) x -= 1;
                    if (Key == 2 && y > 1) y -= 1;
                    if (Key == 3 && x < BOARD_SIZE) x += 1;
                    if (Key == 4 && y < BOARD_SIZE) y += 1;
                    if (Key == 10 && status[x][y].opt == 0) break;
                }
                else { // turn O - 4 arrows
                    if (Key == 11 && x > 1) x -= 1;
                    if (Key == 22 && y > 1) y -= 1;
                    if (Key == 33 && x < BOARD_SIZE) x += 1;
                    if (Key == 44 && y < BOARD_SIZE) y += 1;
                    if (Key == 0 && status[x][y].opt == 0) break;
                }


                if (Key == 5) { // exit game
                    drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 4);
                    while (true) {
                        char key = _getch();
                        if (key == 'N' || key == 'n') break;
                        else if (key == 'Y' || key == 'y') return;
                    } drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
                }
                if (Key == 6) // Undo
                {
                    if (!Cache.empty())
                    {
                        x = Cache.back().F;
                        y = Cache.back().S;
                        Cache.pop_back();
                        makeMove(0, x, y);
                        Turn *= -1;
                        if (Turn == 1) {
                            drawX(XX - 18 + 4 * BOARD_SIZE, YY + 3, 4);
                            drawO(XX - 39, YY + 3, 8);
                        }
                        else {
                            drawO(XX - 39, YY + 3, 1);
                            drawX(XX - 18 + 4 * BOARD_SIZE, YY + 3, 8);
                        } moveTo(x, y);
                    }
                }
                if (Key == 7) { // save game
                    saveGame(XX, YY, Cache, Xscore, Oscore, name1, name2, avatarP1, avatarP2, fileName);
                }
                moveTo(x, y);
            }

            Cache.push_back({ x, y });
            makeMove(Turn, x, y);
            Turn *= -1;

            if (Cache.size() == BOARD_SIZE * BOARD_SIZE) {
                Turn = 0;
                break;
            }
        }

        ShowCur(0);
        displayWinLine();
        system("cls");
        drawGIAO_DAU(XX - 20, YY - 9);
        drawPopUp(XX - 27, YY + 3, 16, 74);
        if (Turn == -1)
        drawX_WIN(XX - 8, YY + 7), Xscore++;    // X Wins
        else if (Turn == 1)
        drawO_WIN(XX - 8, YY + 7), Oscore++;    // O Wins
        else drawDRAW(XX - 7, YY + 7);              // Draw

        gotoXY(XX - 9 - (Turn == -1), YY + 13);
        for (int i = 0; i < 38; ++i)
            cout << char(196);

        gotoXY(XX - 9 - (Turn == -1), YY + 14);
        setColor(15, 8);  cout << "<< Nhan Y de tiep tuc hoac nhan N de thoat >>";
        setColor(15, 0);


        // Hoi nguoi choi co muon choi lai van dau khong
        while (true) {
            char key = _getch();
            if (key == 'N' || key == 'n') break;
            else if (key == 'Y' || key == 'y') {
                isNewGame = 1;
                goto playAgain;
            }
        }
}