#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int triangle[501][501] = {0};
int DP[501][501] = {0};
int answer = 0;

void input()
{
  cin >> N;
  FOR(n, N) {
    FOR(i, n + 1) {
      cin >> triangle[n][i];
    }
  }
}

void solve()
{
  DP[0][0] = triangle[0][0];
  FOR(n, N) {
    FOR(i, n + 1) {
      if (n != 0) {
        if (i == 0) {
          DP[n][i] = max(DP[n][i], DP[n - 1][i] + triangle[n][i]);
        } else if (i == n) {
          DP[n][i] = max(DP[n][i], DP[n - 1][i - 1] + triangle[n][i]);
        } else {
          DP[n][i] = max(max(DP[n - 1][i] + triangle[n][i], DP[n - 1][i - 1] + triangle[n][i]), DP[n][i]);
        }
      }
      answer = max(answer, DP[n][i]);
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