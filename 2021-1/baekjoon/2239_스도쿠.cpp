#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int board[9][9];
bool isExistRow[9][10] = {0};
bool isExistCol[9][10] = {0};
bool isExistCell[9][10] = {0};

bool answerFlag = false;

void input()
{
  FOR(i, 9)
  {
    string tmp;
    cin >> tmp;
    FOR(j, 9)
    {
      board[i][j] = tmp[j] - '0';
      if (board[i][j] != 0)
      {
        isExistRow[i][board[i][j]] = true;
        isExistCol[j][board[i][j]] = true;
        isExistCell[(i / 3 * 3) + (j / 3)][board[i][j]] = true;
      }
    }
  }
}

void find()
{
  FOR(i, 9)
  {
    FOR(j, 9)
    {
      if (board[i][j] == 0)
      {
        FOR(n, 9)
        {
          if (isExistRow[i][n + 1])
            continue;
          if (isExistCol[j][n + 1])
            continue;
          if (isExistCell[(i / 3 * 3) + (j / 3)][n + 1])
            continue;
        
          isExistRow[i][n + 1] = true;
          isExistCol[j][n + 1] = true;
          isExistCell[(i / 3 * 3) + (j / 3)][n + 1] = true;
          board[i][j] = n + 1;
          find();
          if (answerFlag)
            return;
          board[i][j] = 0;
          isExistRow[i][n + 1] = false;
          isExistCol[j][n + 1] = false;
          isExistCell[(i / 3 * 3) + (j / 3)][n + 1] = false;
        }
        return;
      }
    }
  }

  answerFlag = true;
}

void solve()
{
  FOR(i, 9)
  {
    FOR(j, 9)
    {
      if (board[i][j] == 0)
      {
        FOR(n, 9)
        {
          if (isExistRow[i][n + 1])
            continue;
          if (isExistCol[j][n + 1])
            continue;
          if (isExistCell[(i / 3 * 3) + (j / 3)][n + 1])
            continue;

          isExistRow[i][n + 1] = true;
          isExistCol[j][n + 1] = true;
          isExistCell[(i / 3 * 3) + (j / 3)][n + 1] = true;
          board[i][j] = n + 1;
          find();
          if (answerFlag)
            return;
          board[i][j] = 0;
          isExistRow[i][n + 1] = false;
          isExistCol[j][n + 1] = false;
          isExistCell[(i / 3 * 3) + (j / 3)][n + 1] = false;
        }
        return;
      }
    }
  }
}

void print()
{
  FOR(i, 9)
  {
    FOR(j, 9)
    {
      cout << board[i][j];
    }
    cout << '\n';
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}