#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654987654321

int T, M, arr[2][100001] = {0};
long long answer;
long long sum0, sum1;

void input()
{
  answer = INF;
  sum0 = 0;
  sum1 = 0;
  cin >> M;
  FOR(m, M) {
    cin >> arr[0][m];
    sum0 += arr[0][m];
  }
  FOR(m, M) {
    cin >> arr[1][m];
  }
}

void solve()
{
  // int DP[10001] = {0};
  sum0 -= arr[0][0];
  FOR(m, M) {
    if (m > 0) {
      sum0 -= arr[0][m];
      sum1 += arr[1][m - 1];
    }
    // cout << sum0 << ' ' << sum1 << "!!\n";
    answer = min(answer, max(sum0, sum1));
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
  cin >> T;
  FOR(t, T) {
    input();
    solve();
    print();
  }
}