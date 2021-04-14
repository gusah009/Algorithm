#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>

using namespace std; 
static int point = 0;



typedef vector< vector<bool> > mino;

bool gameBoard[22][12] = { 0, };

#define HARD 200
#define NORMAL 300
#define EASY 400
#define DONG "■ "

mino I_mino({
  vector<bool>({1}),
  vector<bool>({1}),
  vector<bool>({1}),
  vector<bool>({1})
    });

mino O_mino({
  vector<bool>({1, 1}),
  vector<bool>({1, 1})
    });

mino Z_mino({
  vector<bool>({0, 1}),
  vector<bool>({1, 1}),
  vector<bool>({1, 0})
    });

mino S_mino({
  vector<bool>({1, 0}),
  vector<bool>({1, 1}),
  vector<bool>({0, 1})
    });

mino J_mino({
  vector<bool>({1, 0, 0}),
  vector<bool>({1, 1, 1})
    });

mino L_mino({
  vector<bool>({0, 0, 1}),
  vector<bool>({1, 1, 1})
    });

mino T_mino({
  vector<bool>({1, 1, 1}),
  vector<bool>({0, 1, 0})
    });

int y_pos, x_pos;

void CursorRemove()
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 0;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    //CursorRemove();
}
void boardPrint() {
    gotoxy(0, 0);
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 12; j++) {
            if (gameBoard[i][j]) {
                cout << DONG;
            }
            else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

void boardSetting() { //테두리 만들기
    for (int i = 0; i < 22; i++) {
        gameBoard[i][0] = true;
        gameBoard[i][11] = true;
    }
    for (int i = 1; i < 11; i++) {
        gameBoard[0][i] = true;
        gameBoard[21][i] = true;
    }
}

mino pickRandomBlock() {
    vector<mino> mino_list({ I_mino, O_mino, Z_mino, S_mino, J_mino, L_mino, T_mino });
    int random_num = rand() % 7;
    return mino_list[random_num];
}

void blockPrint(mino& block) {
    for (int i = 0; i < block.size(); i++) {
        for (int j = 0; j < block[i].size(); j++) {
            gotoxy((x_pos + j) * 2, y_pos + i);
            if (block[i][j]) {
                cout << DONG;
            }
            else {
                cout << "  ";
            }
        }
    }
}

void blockErase(mino& block) {
    for (int i = 0; i < block.size(); i++) {
        for (int j = 0; j < block[i].size(); j++) {
            gotoxy((x_pos + j) * 2, y_pos + i);
            if (gameBoard[y_pos + i][x_pos + j]) {
                cout << DONG;
            }
            else {
                cout << "  ";
            }
        }
    }
}

void boardSet(mino block) {
    for (int i = 0; i < block.size(); i++) {
        for (int j = 0; j < block[i].size(); j++) {
            if ((gameBoard[y_pos + i][x_pos + j] == false) && (block[i][j] == true))
                gameBoard[y_pos + i][x_pos + j] = block[i][j];
        }
    }
}

bool isTouch(mino block) {
    for (int i = 0; i < block.size(); i++) {
        for (int j = 0; j < block[i].size(); j++) {
            if (block[i][j] == true && (i == (block.size() - 1) || block[i + 1][j] == false) && gameBoard[y_pos + i + 1][x_pos + j] == true) {
                return true;
            }
        }
    }
    return false;
}

bool canMoveLeft(mino block) {
    for (int i = 0; i < block.size(); i++) {
        if ((block[i][0] == true) && (gameBoard[y_pos + i][x_pos - 1] == true)) {
            return false;
        }
    }
    return true;
}

bool canMoveRight(mino block) {
    for (int i = 0; i < block.size(); i++) {
        if ((block[i][block[0].size() - 1] == true) && (gameBoard[y_pos + i][x_pos + block[0].size()] == true)) {
            return false;
        }
    }
    return true;
}

void rotation(mino& block) {
    mino next_block(block[0].size());
    for (int j = 0; j < block[0].size(); j++) {
        for (int i = 0; i < block.size(); i++) {
            next_block[j].push_back(block[i][block[0].size() - j - 1]);
        }
    }
    for (int i = 0; i < next_block.size(); i++) {
        for (int j = 0; j < next_block[i].size(); j++) {
            if ((gameBoard[y_pos + i][x_pos + j] == true) && (next_block[i][j] == true))
                return;
        }
    }
    block = next_block;
}
void score() {
    gotoxy(26, 16);
    cout << " Made by : God Hyun Mo " << endl;
    gotoxy(26, 18);
    cout << "↑ : Rotation , ← ↓ → : Moving your block" << endl;
    gotoxy(26, 20); 
    cout << " YOUR SCORE : " << point << endl;

}
void clearLine() {
    int is_clear = 0;
    for (int i = 20; i > 0; i--) {
        for (int j = 1; j < 11; j++) {
            if (gameBoard[i][j]) {
                is_clear++;
            }
        }
        if (is_clear == 10) {
            point += 10;
            for (int k = i; k > 1; k--) {
                for (int j = 1; j < 11; j++) {
                    if (gameBoard[k - 1][j])
                        gameBoard[k][j] = true;
                    else
                        gameBoard[k][j] = false;
                }
            }
            i++;
        }
        is_clear = 0;
    }
}

bool isEndGame() {
    bool is_End = false;
    for (int j = 1; j < 11; j++) {
        if (gameBoard[1][j]) {
            is_End = true;
            break;
        }
    }
    return is_End;
}

void play() {
    while (1) {
        
        boardPrint();
        mino random_block = pickRandomBlock();
        y_pos = 1;
        x_pos = 5;
        while (1) {
            // system("cls"); //화면 클리어
            blockPrint(random_block);
            gotoxy(0, 0);
            score();
            clock_t current_time = clock();
            while (clock() <= current_time + EASY) {
                if (_kbhit()) { // 키보드가 눌렸니? 체크 
                    char iChar = _getch(); // 눌린 값 대입
                    if (iChar == 75) { // 왼쪽
                        if (canMoveLeft(random_block)) {
                            blockErase(random_block);
                            x_pos--;
                            blockPrint(random_block);
                        }
                    }
                    else if (iChar == 77) { //오른쪽
                        if (canMoveRight(random_block)) {
                            blockErase(random_block);
                            x_pos++;
                            blockPrint(random_block);
                        }
                    }
                    else if (iChar == 72) { //위쪽
                        blockErase(random_block);
                        rotation(random_block);
                        blockPrint(random_block);
                    }
                    else if (iChar == 80) { //아래쪽
                        if (!isTouch(random_block)) {
                            blockErase(random_block);
                            y_pos++;
                            blockPrint(random_block);
                        }
                    }
                }
            }

            blockErase(random_block);
            if (isTouch(random_block)) {
                boardSet(random_block);
                clearLine();
                score();
                break;
            }
            y_pos++;
        }
        if (isEndGame())
            break;
    }
}

int main() {
    system("cls"); //화면 클리어
    srand((unsigned int)time(NULL));
    boardSetting();

    play();
    boardPrint();

    gotoxy(0, 24);
    return 0;
}

//system("cls"); //화면 클리어