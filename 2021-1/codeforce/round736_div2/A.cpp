#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, P, a, b;

void input()
{
  cin >> P;
}

void solve()
{
  a = 2;
  if (P == 5) {
    b = 4;
    return;
  }
  b = (P - 1) / a;
}

void print()
{
  cout << a << ' ' << b << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  FOR(t, T)
  {
    input();
    solve();
    print();
  }
}