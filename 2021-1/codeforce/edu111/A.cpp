#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, N, answer;

void input()
{
  cin >> N;
}

void solve()
{
  if (N == 1) {
    answer = 1;
    return;
  }

  int i = 1;
  int total = 0;
  while (total < N) {
    total += i;
    i += 2;
  }
  answer = i / 2;
}

void print()
{
  cout << answer << '\n';
}

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  cin >> T;
  FOR (t, T) {
    input();
    solve();
    print();
  }
}