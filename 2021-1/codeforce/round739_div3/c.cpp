#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, K;
int r, c;

void input()
{
  cin >> K;
}

void solve()
{
  if (K == 1) {
    r = 1;
    c = 1;
    return;
  }
  unsigned long long i = 1;
  while(true) {
    if (i * i >= K) break;
    i++;
  }
  K -= (i - 1) * (i - 1);
  if (K <= i) {
    r = K;
    c = i;
  } else {
    r = i;
    c = i - (K - i);
  }
}

void print()
{
  cout << r << ' ' << c << '\n';
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