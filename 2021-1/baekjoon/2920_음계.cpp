#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int arr[8];
bool flag;
int answer = 0;

void input()
{
  FOR(i, 8) cin >> arr[i];
}

void solve()
{
  flag = arr[0] < arr[1] ? true : false;
  if (flag) {
    FOR(i, 7) {
      if (arr[i] > arr[i + 1]) return;
    }
    answer = 1;
    return;
  } else {
    FOR(i, 7) {
      if (arr[i] < arr[i + 1]) return;
    }
    answer = -1;
    return;
  }
}

void print()
{
  if (answer == 1) {
    cout << "ascending\n";
  } else if (answer == 0) {
    cout << "mixed\n";
  } else if (answer == -1) {
    cout << "descending\n";
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