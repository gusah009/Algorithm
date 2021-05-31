#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321

int N;
int P[1001] = {0};

int main()
{
  cin >> N;
  FOR(n, N) {
    cin >> P[n];
  }
  sort(&P[0], &P[N]);

  int sum = 0;
  FOR(n, N) {
    FOR(i, n) {
      sum += P[i];
    }
    sum += P[n];
    // cout << sum << '\n';
  }

  cout << sum << '\n';
  return 0;
}