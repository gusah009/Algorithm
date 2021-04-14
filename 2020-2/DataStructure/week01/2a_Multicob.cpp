#include <iostream>

using namespace std;

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int K;
int x[51], y[51], C_x[3], C_y[3];
int answer_x, answer_y;
char C_dir[3];
int board[1000][1000][2]; //[0] : 시계방향 , [1] : 반시계방향
int crash[3]; // 01, 12, 20
int T;

void makingBoard(int k)
{
  if (x[k-1] == x[k]) {
    if (y[k] - y[k-1] > 0) {
      for (int i = 0; i < abs(y[k] - y[k-1]); i++) {
        board[x[k]][y[k-1] + i][0] = UP;
        board[x[k]][y[k-1] + i + 1][1] = DOWN;
      }
    } else {
      for (int i = 0; i < abs(y[k] - y[k-1]); i++) {
        board[x[k]][y[k-1] - i][0] = DOWN;
        board[x[k]][y[k-1] - i - 1][1] = UP;
      }
    }
  } else if (y[k-1] == y[k]) {
    if (x[k] - x[k-1] > 0) {
      for (int i = 0; i < abs(x[k] - x[k-1]); i++) {
        board[x[k-1] + i][y[k-1]][0] = RIGHT;
        board[x[k-1] + i + 1][y[k-1]][1] = LEFT;
      }
    } else {
      for (int i = 0; i < abs(x[k] - x[k-1]); i++) {
        board[x[k-1] - i][y[k-1]][0] = LEFT;
        board[x[k-1] - i - 1][y[k-1]][1] = RIGHT;
      }
    }
  }
}

bool crashCheck1(int robot1, int robot2)
{
  if (C_dir[robot1] != C_dir[robot2]) {
    int next1[2];
    int d = C_dir[robot1] == '+' ? 0 : 1;
    switch(board[C_x[robot1]][C_y[robot1]][d]) {
      case UP:
        next1[0] = C_x[robot1];
        next1[1] = C_y[robot1] + 1;
        break;
      case DOWN:
        next1[0] = C_x[robot1];
        next1[1] = C_y[robot1] - 1;
      break;
      case LEFT:
        next1[0] = C_x[robot1] - 1;
        next1[1] = C_y[robot1];
      break;
      case RIGHT:
        next1[0] = C_x[robot1] + 1;
        next1[1] = C_y[robot1];
      break;
    }
    if (next1[0] == C_x[robot2] && next1[1] == C_y[robot2]) {
      return true;
    }
  }
  return false;
}

bool crashCheck2(int robot1, int robot2)
{
  if (C_x[robot1] == C_x[robot2] && C_y[robot1] == C_y[robot2]) {
    return true;
  }
  return false;
}

void moving(int robot) 
{
  int d = C_dir[robot] == '+' ? 0 : 1;
  switch(board[C_x[robot]][C_y[robot]][d]) {
    case UP:
      C_y[robot]++;
      break;
    case DOWN:
      C_y[robot]--;
    break;
    case LEFT:
      C_x[robot]--;
    break;
    case RIGHT:
      C_x[robot]++;
    break;
  }
}

int main()
{

  cin >> K;
  cin >> x[0] >> y[0];
  for (int k = 1; k <= K; k++) {
    if (k != K) {
      cin >> x[k] >> y[k];
    } else {
      x[K] = x[0];
      y[K] = y[0];
    }
    makingBoard(k);
  }
  for (int c = 0; c < 3; c++) {
    cin >> C_x[c] >> C_y[c] >> C_dir[c];
  }
  cin >> T;

  for (int t = 0; t < T; t++) {
    for (int i = 0; i < 3; i++) {
      if (crashCheck1(i, (i+1)%3)) { // 둘이 1번경우에서 부딪혔다면
        C_dir[i] = C_dir[i] == '+' ? '-' : '+';
        C_dir[(i+1)%3] = C_dir[(i+1)%3] == '+' ? '-' : '+';
        crash[i] = 1;
        crash[(i+1)%3] = 1;
      } else if (crashCheck2(i, (i+1)%3)) { // 둘이 2번경우에서 부딪혔다면
        C_dir[i] = C_dir[i] == '+' ? '-' : '+';
        C_dir[(i+1)%3] = C_dir[(i+1)%3] == '+' ? '-' : '+';
      } else { // 안부딪혔다면
      }
    }
    for (int i = 0; i < 3; i++) {
      if (crash[i] != 1) {
        moving(i);
      }
      crash[i] = 0;
    }
    cout << "t: " << t << "\n";
    for (int i = 0; i < 3; i++) {
      cout << C_x[i] << " " << C_y[i] << "\n";
    }
  }

  for (int i = 0; i < 3; i++) {
    cout << C_x[i] << " " << C_y[i] << "\n";
  }
}