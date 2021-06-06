#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int board[501][501];
bool isVisited[501][501] = {0};
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int answer = -1;

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    FOR(m, M) {
      cin >> board[n][m];
    }
  }
}

void fillBoard(int n, int m, int depth, int sum)
{
  if (depth == 4) {
    answer = answer < sum ? sum : answer;
    return;
  }

  if (depth == 2) {
    FOR(i, 4) {
      int next_n1 = n + dir[i][0];
      int next_m1 = m + dir[i][1];
      int next_n2 = n + dir[(i + 1) % 4][0];
      int next_m2 = m + dir[(i + 1) % 4][1];
      if (0 <= next_n1 && next_n1 < N && 0 <= next_m1 && next_m1 < M) {
        if (0 <= next_n2 && next_n2 < N && 0 <= next_m2 && next_m2 < M) {
          if (!isVisited[next_n1][next_m1] && !isVisited[next_n2][next_m2])
            fillBoard(next_n2, next_m2, depth + 2, sum + board[next_n1][next_m1] + board[next_n2][next_m2]);
        }
      }
    }
  }

  FOR(i, 4) {
    int next_n = n + dir[i][0];
    int next_m = m + dir[i][1];
    if (0 <= next_n && next_n < N && 0 <= next_m && next_m < M) {
      if (!isVisited[next_n][next_m]) {
        isVisited[next_n][next_m] = true;
        fillBoard(next_n, next_m, depth + 1, sum + board[next_n][next_m]);
        isVisited[next_n][next_m] = false;
      }
    }
  }
}

void solve()
{
  FOR(n, N) {
    FOR(m, M) {
      isVisited[n][m] = true;
      fillBoard(n, m, 1, board[n][m]);
      isVisited[n][m] = false;
    }
  }
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