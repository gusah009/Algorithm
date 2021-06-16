#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, M;
int board[1001][1001] = {0};
int DP[1001][1001][2] = {0};
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
queue<pair<int, int> > Q;

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    string tmp;
    cin >> tmp;
    FOR(i, tmp.size()) {
      board[n][i] = tmp[i] - '0';
      DP[n][i][0] = INF;
      DP[n][i][1] = INF;
    }
  }
}

void BFS() {
  while (!Q.empty()) {
    int n = Q.front().first;
    int m = Q.front().second;
    Q.pop();
    if (n == N - 1 && m == M - 1) break;
    FOR(i, 4) {
      int next_n = n + dir[i][0];
      int next_m = m + dir[i][1];
      if (0 <= next_n && next_n < N) {
        if (0 <= next_m && next_m < M) {
          if (board[next_n][next_m] == 1) {
            if (DP[n][m][0] != INF) {
              if (DP[next_n][next_m][1] > DP[n][m][0] + 1) {
                DP[next_n][next_m][1] = DP[n][m][0] + 1;
                Q.push(make_pair(next_n, next_m));
              }
            }
          } else {
            if (DP[n][m][0] != INF) {
              if (DP[next_n][next_m][0] > DP[n][m][0] + 1) {
                DP[next_n][next_m][0] = DP[n][m][0] + 1;
                Q.push(make_pair(next_n, next_m));
              }
            }
            if (DP[n][m][1] != INF) {
              if (DP[next_n][next_m][1] > DP[n][m][1] + 1) {
                DP[next_n][next_m][1] = DP[n][m][1] + 1;
                Q.push(make_pair(next_n, next_m));
              }
            }
          }
        }
      } 
    }
  }
}

void solve()
{
  DP[0][0][0] = 1;
  Q.push(make_pair(0, 0));
  BFS();
}

void print()
{
  FOR(n, N) {
    FOR(m, M) {
      cout << DP[n][m][0] << ' ';
    }
    cout << '\n';
  }

  FOR(n, N) {
    FOR(m, M) {
      cout << DP[n][m][1] << ' ';
    }
    cout << '\n';
  }
  // int answer = min(DP[N - 1][M - 1][0], DP[N - 1][M - 1][1]);
  // if (answer == INF) cout << -1 << '\n';
  // else cout << answer << '\n';
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