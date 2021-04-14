#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX_N 30
#define MAX_M 30

int N, M, k, msize = 0, w = 0;
char board[MAX_M][MAX_N];
int moving[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void input()
{
  cin >> N >> M >> k;
  FOR(m, M) {
    FOR(n, N) {
      cin >> board[m][n];
    }
  }
}

int sizeOfVirus(int y, int x) {
  if (y < 0 || x < 0 || x >= N || y >= M) {
    return 0;
  }
  if (board[y][x] == '_') {
    return 0;
  }
  board[y][x] = '_';
  int size = 1;
  FOR(i, 4) {
    size += sizeOfVirus(y + moving[i][0], x + moving[i][1]);
  }
  return size;
}

void solve()
{
  FOR(m, M) {
    FOR(n, N) {
      int size = sizeOfVirus(m, n);
      if (size >= k) {
        w++;
        if (msize < size) msize = size;
      }
    }
  }

}

void print()
{
  cout << w << " " << msize << "\n";
}

int main()
{
  input();
  solve();
  print();
}