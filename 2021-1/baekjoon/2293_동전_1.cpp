#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, K;
int coin[101];
int dp[10001];

void input()
{
  cin >> N >> K;
  FOR(n, N) {
    cin >> coin[n];
  }
  sort(coin, coin + N);
}


void solve()
{
  dp[0] = 1;
  FOR(n, N) {
    for(int k = 1; k <= K; k++) {
      if (k - coin[n] >= 0) {
        dp[k] += dp[k - coin[n]];
      }
    }
  }
}

void print()
{
  cout << dp[K];
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