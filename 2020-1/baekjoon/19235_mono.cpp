#include <iostream>
#include <vector>
using namespace std;

int N;
bool board[10][10] = {0};
int answer = 0, answer2 = 0;

void move(bool color) // 완전히 딱 붙게
{
  if (color) { // 초록
    for (int j = 0; j < 4; j++) {
      for (int i = 9; i > 4; i--) {
        for (int k = i - 1; k > 4; k--) {
          if (board[i][j] == 0 && board[k][j] == 1) {
            board[i][j] = 1;
            board[k][j] = 0;
          }
        }
      }
    }
  }
  else { // 파랑
    for (int j = 0; j < 4; j++) {
      for (int i = 9; i > 4; i--) {
        for (int k = i - 1; k > 4; k--) {
          if (board[j][i] == 0 && board[j][k] == 1) {
            board[j][i] = 1;
            board[j][k] = 0;
          }
        }
      }
    }
  }
}

void remove(int line, bool color) 
{
  if (color == true) { // 초록진영
    for (int i = 0; i < 4; i++) {
      board[line + 4][i] = 0;
    }
  }
  else { // 파랑진영
    for (int i = 0; i < 4; i++) {
      board[i][line + 4] = 0;
    }
  }
}

bool find(int line, bool color)
{
  bool result;
  int i;
  if (color) { // 초록진영
    for (i = 0; i < 4; i++) {
      if (board[line + 4][i] == false) {
        break;
      }
    }
  }
  else { // 파랑진영
    for (i = 0; i < 4; i++) {
      if (board[i][line + 4] == false) {
        break;
      }
    }
  }
  if (i == 4) {
    return true;
  }
  else {
    return false;
  }
}

void zero_one(int line) // line번째 줄
{
  int i, result = 0;
  for (i = 0; i < 4; i++) { //초록진영
    if (board[line + 4][i] == 1) {
      break;
    } 
  }
  if (i != 4) { // 0이나 1에 있다면
    remove(5, true);
    for (int j = 4 + 4; j >= 4 + 0; j--) {
      for (int k = 0; k < 4; k++) {
        board[j+1][k] = board[j][k];
      }
    }
    for (int k = 0; k < 4; k++) {
      board[line + 4][k] = 0;
    }
  }
  for (i = 0; i < 4; i++) { //파랑진영
    if (board[i][line + 4] == 1) {
      break;
    } 
  }
  if (i != 4) { // 0이나 1에 있다면
    remove(5, false);
    for (int j = 4 + 4; j >= 4 + 0; j--) {
      for (int k = 0; k < 4; k++) {
        board[k][j+1] = board[k][j];
      }
    }
    for (int k = 0; k < 4; k++) {
      board[k][line + 4] = 0;
    }
  }
}

void input_solve()
{
  int t, x, y; 
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> t >> x >> y;
    int g_x = x, g_y = y;
    int b_x = x, b_y = y;
    // 쌓기
    if (t == 1) {
      while (g_y < 10 && board[g_y++][g_x] == 0) {} // 초록진영
      board[g_y - 1][g_x] = 1;
      //-------------------------------------------
      while (b_x < 10 && board[b_y][b_x++] == 0) {} // 파랑진영
      board[b_y][b_x - 1] = 1;
    }
    else if (t == 2) {
      while (g_y + 1 < 10 && (board[g_y][g_x] == 0 && board[g_y + 1][g_x] == 0)) {g_y++;} // 초록진영
      board[g_y][g_x] = 1;
      board[g_y - 1][g_x] = 1;
      //-------------------------------------------
      while (b_x < 10 && (board[b_y][b_x] == 0 && board[b_y + 1][b_x] == 0)) {b_x++;} // 파랑진영
      board[b_y + 1][b_x - 1] = 1;
      board[b_y][b_x - 1] = 1;
    }
    else if (t == 3) {
      while (g_y < 10 && (board[g_y][g_x] == 0 && board[g_y][g_x + 1] == 0)) {g_y++;} // 초록진영
      board[g_y - 1][g_x] = 1;
      board[g_y - 1][g_x + 1] = 1;
      //-------------------------------------------
      while (b_x + 1 < 10 && (board[b_y][b_x] == 0 && board[b_y][b_x + 1] == 0)) {b_x++;} // 파랑진영
      board[b_y][b_x - 1] = 1;
      board[b_y][b_x] = 1;
    }

  // for (int i = 0; i < 10; i++) {
  //   for (int j = 0; j < 10; j++) {
  //     cout << board[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

    // for문 돌면서 찾기, 제거, 이동 반복
    bool result_g = true;
    bool result_b = true;
    int rg = 0;
    while(rg != 4) {
      rg = 0;
      for (int i = 5; i >= 2; i--) {
        result_g = find(i, true);
        if (result_g) {
          answer++;
          remove(i, true);
        }
        else {
          rg++;
        }
      }
      move(true);
    }
    int rb = 0;
    while(rb != 4) {
      rb = 0;
      for (int i = 5; i >= 2; i--) {
        result_b = find(i, false);
        if (result_b) {
          answer++;
          remove(i, false);
        }
        else {
          rb++;
        }
      }
      move(false);
    }
  }
  for (int i = 0; i < 2; i++) {
    zero_one(i);
  }
}

void print()
{
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      // cout << board[i][j] << " ";
      if (board[i][j] == 1) {
        answer2++;
      }
    }
    // cout << "\n";
  }
  cout << answer << "\n" << answer2 << "\n";
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve();
  print();
}