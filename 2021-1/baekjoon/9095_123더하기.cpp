#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, N;
int answer = 0;

void input()
{
  answer = 0;
  cin >> N;
}

void counting(int n) {
  if (n == N) {
    answer++;
    return;
  } else if (n > N) {
    return;
  } else {
    counting(n + 1);
    counting(n + 2);
    counting(n + 3);
  }
}

void solve()
{
  counting(0);
}

void print()
{
  cout << answer << '\n';
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