#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, T;
pair<int, int> DP[41];

pair<int, int> fibonacci(int n) {
    if (DP[n].first != 0 || DP[n].second != 0) {
      return DP[n];
    }

    if (n == 0) {
      DP[0] = make_pair(1, 0);
      return DP[0];
    } else if (n == 1) {
      DP[1] = make_pair(0, 1);
      return DP[1];
    } else {
      DP[n] = make_pair(fibonacci(n - 1).first + fibonacci(n - 2).first, fibonacci(n - 1).second + fibonacci(n - 2).second);
      return DP[n];
    }
}

void input()
{
  cin >> T;
  FOR(t, T) {
    FOR(i, 40) {
      DP[i].first = 0;
      DP[i].second = 0;
    }
    cin >> N;
    fibonacci(N);
    cout << DP[N].first << ' ' << DP[N].second << '\n';
  }
}

void solve()
{
}

void print()
{
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