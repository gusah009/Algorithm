#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, N, W, result;
int DP[3][10001];
int enemy[2][10001];

void input()
{
  result = 0;

  cin >> N >> W;
  FOR(i, 2) {
    FOR(n, N) {
      cin >> enemy[i][n];
    }
  }

  DP[0][0] = enemy[0][0] + enemy[1][0] <= W ? 1 : 2;
  DP[1][0] = 1;
  DP[2][0] = 1;
}

void DPFunc(int start) {
  for(int n = start; n < N; n++) {
    DP[1][n] = DP[0][n - 1] + 1;
    if (enemy[0][n - 1] + enemy[0][n] <= W) {
      DP[1][n] = min(DP[1][n], DP[2][n - 1] + 1);
    }
    DP[2][n] = DP[0][n - 1] + 1;
    if (enemy[1][n - 1] + enemy[1][n] <= W) {
      DP[2][n] = min(DP[2][n], DP[1][n - 1] + 1);
    }
    DP[0][n] = min(DP[1][n] + 1, DP[2][n] + 1);
    if (enemy[0][n] + enemy[1][n] <= W) {
      DP[0][n] = min(DP[0][n], DP[0][n - 1] + 1);
    }
    if (enemy[0][n] + enemy[0][n-1] <= W && enemy[1][n] + enemy[1][n-1] <= W) {
      if (n > 1) {
        DP[0][n] = min(DP[0][n], DP[0][n - 2] + 2);
      } else {
        DP[0][n] = min(DP[0][n], 2);
      }
    }
  }
}

void solve()
{
  DPFunc(1);
  result = DP[0][N - 1];
  

  if (N > 1 && enemy[0][0] + enemy[0][N-1] <= W) {
    DP[0][0] = 1;
    DP[1][0] = 0;
    DP[2][0] = 1;
    DP[1][1] = 2;
    DP[2][1] = enemy[1][0] + enemy[1][1] <= W ? 1 : 2;
    DP[0][1] = min(DP[1][1] + 1, DP[2][1] + 1);
    if (enemy[0][1] + enemy[1][1] <= W) {
      DP[0][1] = min(DP[0][1], DP[0][0] + 1);
    }
    DPFunc(2);
    result = min(result, DP[2][N-1] + 1);
  }

  if (N > 1 && enemy[1][0] + enemy[1][N-1] <= W) {
    DP[0][0] = 1;
    DP[1][0] = 1;
    DP[2][0] = 0;
    DP[1][1] = enemy[0][0] + enemy[0][1] <= W ? 1 : 2;
    DP[2][1] = 2;
    DP[0][1] = min(DP[1][1] + 1, DP[2][1] + 1);
    if (enemy[0][1] + enemy[1][1] <= W) {
      DP[0][1] = min(DP[0][1], DP[0][0] + 1);
    }
    DPFunc(2);
    result = min(result, DP[1][N-1] + 1);
  }

  if (N > 1 && enemy[0][0] + enemy[0][N-1] <= W && enemy[1][0] + enemy[1][N-1] <= W) {
    DP[0][0] = 0;
    DP[1][0] = 0;
    DP[2][0] = 0;
    DP[1][1] = DP[2][1] = 1;
    DP[0][1] = 2;
    if (enemy[0][1] + enemy[1][1] <= W) {
      DP[0][1] = min(DP[0][1], DP[0][0] + 1);
    }
    DPFunc(2);
    result = min(result, DP[0][N-2] + 2);
  }
}

void print()
{
  cout << result << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  FOR(t, T) {
    input();
    solve();
    print();
  }
}