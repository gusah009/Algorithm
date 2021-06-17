#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321

int N, M, K;
long long arr[1000001] = {0};
long long DP[1000001] = {0};
vector<pair<pair<long long, long long>, long long> > add;

void input_solve_print()
{
  cin >> N >> M >> K;
  FOR(n, N) {
    cin >> arr[n + 1];
  }
  DP[0] = 0;
  FOR(n, N) {
    DP[n + 1] = DP[n] + arr[n + 1];
  }

  FOR(i, M + K) {
    long long a, b, c;
    cin >> a;
    if (a == 1) {
      long long d;
      cin >> b >> c >> d;
      add.push_back(make_pair(make_pair(b, c), d));
    } else if (a == 2) {
      cin >> b >> c;
      long long result = DP[c] - DP[b - 1];
      FOR(j, add.size()) {
        long long x = max(add[j].first.first, b);
        long long y = min(add[j].first.second, c);
        if (y - x >= 0) {
          result += (y - x + 1) * add[j].second;
        }
      }
      cout << result << '\n';
    }
  }
}


int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve_print();
}