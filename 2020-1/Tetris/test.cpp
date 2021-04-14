#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>

using namespace std;
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

int main() {
  cout << "한글은 되냐?";
}