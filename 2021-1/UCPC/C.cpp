#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

double a, d, k;
double answer = 0;

void input()
{
  cin >> a >> d >> k;
  d = d / 100;
  k = k / 100;
}

void solve_print()
{
  if (d == 1) {
    cout << a << '\n';
    return;
  }
  double win_rate = 0, def_rate = 0;
  win_rate = d;
  def_rate = 1 - d;
  long long i = 1;
  while (d < 1) {
    answer += a * win_rate * i;
    d += d * k;
    win_rate = def_rate * d;
    if ((1 - d) > 0) {
      def_rate = def_rate * (1 - d);
    }
    i++;
  }
  answer += a * def_rate * i;

  cout << fixed;
  cout.precision(9);
  cout << answer << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve_print();
}