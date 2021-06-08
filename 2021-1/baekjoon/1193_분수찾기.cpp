#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int X;

void input()
{
  cin >> X;
}

void solve()
{
  int x = 0;
  int n = 1;
  bool even = false;
  if (X == 1) {
    cout << "1/1\n";
    return;
  }
  while(x != X) {
    if (even) {
      FOR(i, n) {
        x++;
        if (x == X) {
          cout << i + 1 << '/' << n - i << '\n';
          break;
        }
      }
    }
    else {
      FOR(i, n) {
        x++;
        if (x == X) {
          cout << n - i << '/' << i + 1 << '\n';
          break;
        }
      }
    }
    even = !even;
    n++;
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
  input();
  solve();
  print();
}