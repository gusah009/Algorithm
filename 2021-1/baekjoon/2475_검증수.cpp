#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int arr[5];
int result = 0;

void input()
{
  FOR(i, 5) cin >> arr[i];
}

void solve()
{
  FOR(i, 5) result += arr[i] * arr[i];
}

void print()
{
  cout << result % 10 << '\n';
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