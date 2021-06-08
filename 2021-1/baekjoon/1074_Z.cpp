#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, r, c;

void input()
{
  cin >> N >> r >> c;
}

void finding(int a, int b, int n, long long answer)
{
  if (n == -1) {
    // cout << a << ' ' << b << ' ' << answer << '\n';
    cout << answer << '\n';
    return;
  }

  int new_a, new_b;
  long long half = pow(2, n);
  if (r < a + half && c < b + half) {
    finding(a, b, n - 1, answer);
  } else if (r < a + half && c >= b + half) {
    finding(a, b + half, n - 1, answer + half * half);
  } else if (r >= a + half && c < b + half) {
    finding(a + half, b, n - 1, answer + half * half * 2);
  } else {
    finding(a + half, b + half, n - 1, answer + half * half * 3);
  }
}

void solve()
{
  finding(0, 0, N - 1, 0);
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