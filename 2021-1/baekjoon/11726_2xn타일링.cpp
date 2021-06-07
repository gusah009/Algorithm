#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int DP[1001] = {0};
int N, M;

void input()
{
  cin >> N;
}

void solve()
{
  DP[0] = 0;
  DP[1] = 1;
  DP[2] = 2;
  for (int n = 3; n <= N; n++) {
    DP[n] = DP[n - 2] + DP[n - 1];
    DP[n] %= 10007;
  }
}

void print()
{
  cout << DP[N] << '\n';
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