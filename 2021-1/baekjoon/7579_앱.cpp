#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M, b[101], c[101], dp[10001], ans;

void input()
{
	cin >> N >> M;
  FOR(n, N) cin >> b[n];
  FOR(n, N) cin >> c[n];
}

void solve()
{
	dp[0] = 0;
	FOR(n, N)
		for (int j = 10000; j >= c[n]; j--)			
			dp[j] = max(dp[j], dp[j - c[n]] + b[n]);

	FOR(n, 10000) if (dp[n] >= M) {
		ans = n;
		break;
	}
}

void print()
{
	cout << ans << '\n';
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