#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int R, C;
char board[21][21] = {0};
int moving[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int answer = 0;

void input()
{
  cin >> R >> C;
  FOR(r, R) {
    FOR(c, C) {
      cin >> board[r][c];
    }
  }
}

void DFS(int i, int j, int depth, int path)
{
  // cout << i << ' ' << j << ' ' << depth  << '\n';

  answer = max(answer, depth);

  FOR(a, 4) {
    int next_i = i + moving[a][0];
    int next_j = j + moving[a][1];
    if (0 <= next_i && next_i < R) {
      if (0 <= next_j && next_j < C) {
        if (path >> (board[next_i][next_j] - '0') & 1) {
          continue;
        }
        DFS(next_i, next_j, depth + 1, path | (1 << (board[next_i][next_j] - '0')));
      }
    }
  }

  return;
}

void solve()
{
  int path = (1 << board[0][0] - '0');
  DFS(0, 0, 1, path);
}

void print()
{
  cout << answer << '\n';
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