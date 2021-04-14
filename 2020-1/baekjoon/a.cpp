#include <iostream>
#include <algorithm>

using namespace std;

int N;
int answer = -1;

void move_board(int copy_board[20][20], int moving, int depth) {
  int board[20][20];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = copy_board[i][j];
    }
  }

  if (depth == 5 + 1) {
    for (int n = 0; n < N; n++) {
      for (int n2 = 0; n2 < N; n2++) {
        answer = max(answer, board[n][n2]);
      }
    }
    return;
  }

  switch (moving) {
  case 0: //UP
    for (int n = 0; n < N; n++) {
      for (int cursor = 0; cursor < N - 1; cursor++) {
        for (int n2 = cursor + 1; n2 < N; n2++) {
          if (board[cursor][n] != board[n2][n]) {
            if (board[cursor][n] == 0) {
              board[cursor][n] = board[n2][n];
              board[n2][n] = 0;
            }
            else if (board[n2][n] != 0){
              board[cursor + 1][n] = board[n2][n];
              if (cursor + 1 != n2) {
                board[n2][n] = 0;
              }
              break;
            }
          }
          else { // 같으면
            if (board[cursor][n] != 0) {
              board[cursor][n] *= 2;
              board[n2][n] = 0;
              break;
            }
          }
        }
      }
    }
    break;
  case 1: //DOWN
    for (int n = 0; n < N; n++) {
      for (int cursor = N - 1; cursor > 0; cursor--) {
        for (int n2 = cursor - 1; n2 >= 0; n2--) {
          if (board[cursor][n] != board[n2][n]) {
            if (board[cursor][n] == 0) {
              board[cursor][n] = board[n2][n];
              board[n2][n] = 0;
            }
            else if (board[n2][n] != 0){
              board[cursor - 1][n] = board[n2][n];
              if (cursor - 1 != n2) {
                board[n2][n] = 0;
              }
              break;
            }
          }
          else { // 같으면
            if (board[cursor][n] != 0) {
              board[cursor][n] *= 2;
              board[n2][n] = 0;
              break;
            }
          }
        }
      }
    }
    break;
  case 2: //RIGHT

    for (int n = 0; n < N; n++) {
      for (int cursor = N - 1; cursor > 0; cursor--) {
        for (int n2 = cursor - 1; n2 >= 0; n2--) {
          if (board[n][cursor] != board[n][n2]) {
            if (board[n][cursor] == 0) {
              board[n][cursor] = board[n][n2];
              board[n][n2] = 0;
            }
            else if (board[n][n2] != 0){
              board[n][cursor - 1] = board[n][n2];
              if (cursor - 1 != n2) {
                board[n][n2] = 0;
              }
              break;
            }
          }
          else { // 같으면
            if (board[n][cursor] != 0) {
              board[n][cursor] *= 2;
              board[n][n2] = 0;
              break;
            }
          }
        }
      }
    }
    break;
  case 3: //LEFT
    for (int n = 0; n < N; n++) {
      for (int cursor = 0; cursor < N - 1; cursor++) {
        for (int n2 = cursor + 1; n2 < N; n2++) {
          if (board[n][cursor] != board[n][n2]) {
            if (board[n][cursor] == 0) {
              board[n][cursor] = board[n][n2];
              board[n][n2] = 0;
            }
            else if (board[n][n2] != 0){
              board[n][cursor + 1] = board[n][n2];
              if (cursor + 1 != n2) {
                board[n][n2] = 0;
              }
              break;
            }
          }
          else { // 같으면
            if (board[n][cursor] != 0) {
              board[n][cursor] *= 2;
              board[n][n2] = 0;
              break;
            }
          }
        }
      }
    }
    break;
  }
  for (int i = 0; i < 4; i++) {
    move_board(board, i, depth + 1);
  }
}

int main()
{
  int board[20][20];
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    move_board(board, i, 1);
  }
  cout << answer;
}