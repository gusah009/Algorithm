#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int board[9][9];
bool isExistRow[9][10] = {0};
bool isExistCol[9][10] = {0};
bool isExistDiag[9][10][2] = {0};
bool answerFlag = false;
int X = 0;

void input()
{
  FOR(i, 9) {
    string tmp;
    cin >> tmp;
    FOR(j, 9) {
      board[i][j] = tmp[j] - '0';
      if (board[i][j] != 0) {
        isExistRow[i][board[i][j]] = true;
        isExistCol[j][board[i][j]] = true;
        if (i == j) isExistDiag[i][board[i][j]][0] = true;
        if (i == 8 - j) isExistDiag[i][board[i][j]][1] = true;
      }
    }
  }
}

void find()
{
  FOR(i, 9) {
    FOR(j, 9) {
      // if (i == 7 && j == 7) { 
      //   FOR(i, 9) {
      //     FOR(j, 9) {
      //       cout << board[i][j];
      //     }
      //     cout << '\n';
      //   }
      // }
      if (board[i][j] == 0) {
        FOR(n, 9) {
          if (isExistRow[i][n + 1]) continue;
          if (isExistCol[j][n + 1]) continue;
          if (i == j && isExistDiag[i][n + 1][0]) continue;
          if (i == 8 - j && isExistDiag[i][n + 1][1]) continue;
          // cout << i << ' ' << j << ' ' << n << '\n';
          isExistRow[i][n + 1] = true;
          isExistCol[j][n + 1] = true;
          if (i == j) isExistDiag[i][n + 1][0] = true;
          if (i == 8 - j) isExistDiag[i][n + 1][1] = true;
          board[i][j] = n + 1;
          find();
          X++;
          if (answerFlag) return;
          board[i][j] = 0;
          isExistRow[i][n + 1] = false;
          isExistCol[j][n + 1] = false;
          if (i == j) isExistDiag[i][n + 1][0] = false;
          if (i == 8 - j) isExistDiag[i][n + 1][1] = false;
        }
        return;
      }
    }
  }

  answerFlag = true;
}

void solve()
{
  FOR(i, 9) {
    FOR(j, 9) {
      if (board[i][j] == 0) {
        FOR(n, 9) {
          if (isExistRow[i][n + 1]) continue;
          if (isExistCol[j][n + 1]) continue;
          if (i == j && isExistDiag[i][n + 1][0]) continue;
          if (i == 8 - j && isExistDiag[i][n + 1][1]) continue;
          cout << i << ' ' << j << ' ' << n + 1 << '\n';
          isExistRow[i][n + 1] = true;
          isExistCol[j][n + 1] = true;
          if (i == j) isExistDiag[i][n + 1][0] = true;
          if (i == 8 - j) isExistDiag[i][n + 1][1] = true;
          board[i][j] = n + 1;
          find();
          X++;
          if (answerFlag) return;
          board[i][j] = 0;
          isExistRow[i][n + 1] = false;
          isExistCol[j][n + 1] = false;
          if (i == j) isExistDiag[i][n + 1][0] = false;
          if (i == 8 - j) isExistDiag[i][n + 1][1] = false;
        }
        return;
      }
    }
  }
}

void print()
{
  FOR(i, 9) {
    FOR(j, 9) {
      cout << board[i][j];
    }
    cout << '\n';
  }
  cout << X << ' ' << answerFlag;
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}