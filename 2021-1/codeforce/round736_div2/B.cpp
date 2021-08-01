#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, N, score;
string enemy, mine;

void input()
{
  cin >> N;
  cin >> enemy;
  cin >> mine;

  score = 0;
}

void solve()
{
  FOR(n, N) {
    if (enemy[n] == '0' && mine[n] == '1') {
      mine[n] = '0';
      score++;
    }
  }

  FOR(n, N) {
    if (n - 1 >= 0) {
      if (enemy[n] == '1' && mine[n - 1] == '1') {
        enemy[n] = '0';
        mine[n - 1] = '0';
        score++;
      }
    }
    if (n + 1 < N) {
      if (enemy[n] == '1' && mine[n + 1] == '1') {
        enemy[n] = '0';
        mine[n + 1] = '0';
        score++;
      }
    }
  }
}

void print()
{
  cout << score << '\n';
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