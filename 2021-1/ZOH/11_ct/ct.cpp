#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N;
int d[8], r[8], rd[8], ld[8];
char board[8][8];
int cnt = 0;
bool flag = false;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void input()
{
  ifstream in("ct.inp");
  in >> N;
  FOR(n, N)
  {
    in >> d[n];
    cnt += d[n];
  }
  FOR(n, N)
  {
    in >> r[n];
  }
  FOR(n, N * 2 - 1)
  {
    in >> rd[n];
  }
  FOR(n, N * 2 - 1)
  {
    in >> ld[n];
  }
  in.close();

  FOR(i, 8) {
    FOR(j, 8) {
      board[i][j] = '-';
    }
  }
}

void DFS(int i, int j, int c)
{
  if (c == cnt) {
    cout << '\n';
    flag = true;
    return;
  }
  if (r[i] == 0 || d[j] == 0 || \ 
      rd[i + (N - j - 1)] == 0 || ld[i + j] == 0) {
    return;
  }
  FOR(i, N) {
    FOR(j, N) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  cout<< '\n';
  r[i]--;
  d[j]--;
  rd[i + (N - j - 1)]--;
  ld[i + j]--;
  board[i][j] = 'B';
  // cout << i << " " << j << board[i][j] << '\n';
  FOR(d, 4) {
    int next_i = i + dir[d][0];
    int next_j = j + dir[d][1];
    if (0 < next_i && next_i < N && \
        0 < next_j && next_j < N && !flag) {
        DFS(next_i, next_j, c + 1);
      }
    if (flag) return;
  }
  board[i][j] = '-';
  r[i]++;
  d[j]++;
  rd[i + (N - j - 1)]++;
  ld[i + j]++;
  return;
}

void solve()
{
  FOR(i, N) {
    FOR(j, N) {
      DFS(i, j, 0);
      if (flag) {
        return;
      }
    }
  }
}

void print()
{
  FOR(i, N) {
    FOR(j, N) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  ofstream out("ct.out");
  FOR(i, N) {
    FOR(j, N) {
      out << board[i][j] << ' ';
    }
    out << '\n';
  }
  out.close();
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