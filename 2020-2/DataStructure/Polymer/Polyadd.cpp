#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M, c, e, counting;
int polymer[1001] = {0};

void print()
{
  if (counting == 0) {
    cout << "1" << "\n" << "0 0" << "\n";
  } else {
    cout << counting << "\n";
    for (int i = 1000; i >= 0; i--) {
      if (polymer[i] != 0) {
        cout << polymer[i] << " "  << i << "\n";
      }
    }
  }
}

void solve()
{
  counting = 0;
  FOR(i, 1000) {
    if (polymer[i] != 0) {
      counting += 1;
    }
  }
}

void input()
{
  cin >> N;
  FOR(n, N) {
    cin >> M;
    FOR(m, M) {
      cin >> c >> e;
      polymer[e] += c;
    }
  }
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