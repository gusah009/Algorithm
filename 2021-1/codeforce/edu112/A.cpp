#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T;
long long N, answer;

void input()
{
  cin >> N;
}

void solve()
{
  if (N < 6) {
    answer = 15;
    return;
  }

  N = N % 2 == 0 ? N : N + 1;
  answer = N * 5 / 2;
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