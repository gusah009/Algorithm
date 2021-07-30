#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, N, a, b, answer;
string inp;

void input()
{
  cin >> N >> a >> b;
  cin >> inp;
}

void solve()
{
  if (b >= 0) {
    answer = N * (a + b);
    return;
  }

  int diff_part = 1;
  FOR(n, N - 1) {
    if (inp[n] != inp[n + 1]) {
      diff_part++;
    }
  }
  answer = a * N + b * (diff_part / 2 + 1);
  // answer += a * len + b;
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