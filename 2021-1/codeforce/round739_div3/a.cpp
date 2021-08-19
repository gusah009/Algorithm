#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, K;
int DP[10000000] = {0};

void input()
{
  cin >> K;
  cout << DP[K - 1] << '\n';
}

bool check(int i)
{
  int tmp = i;
  if(tmp % 10 == 3) return true;
  return false;
}

void solve()
{
  int k = 0;
  int i = 1;
  while (true) {
    if (k == 1000) break;

    if (i % 3 == 0) {
      
    } else if (check(i)) {

    } else {
      DP[k++] = i;
    }

    i++;
  }
}
int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  cin >> T;
  FOR(t, T) {
    input();
  }
}