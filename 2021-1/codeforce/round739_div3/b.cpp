#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T;
int a, b, c;

void input()
{
  cin >> a >> b >> c;
}

void solve()
{
  if (a > b) {
    swap(a, b);
  }
  int maximum = 2 * (b - a);
  if (a - 1 > b - a - 1){
    cout << -1 << '\n';
    return;
  }
  if (c > maximum) {
    cout << -1 << '\n';
    return;
  }

  if (c > (b - a)) {
    cout << c - (b - a) << '\n';
  } else {
    cout << c + (b - a) << '\n';
  }
}

void print()
{

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