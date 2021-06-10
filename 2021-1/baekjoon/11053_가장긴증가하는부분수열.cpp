#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int A;
int arr[1001] = {0};
int DP[1001] = {0};
int answer = -1;

void input()
{
  cin >> A;
  FOR(a, A) {
    cin >> arr[a];
  }
}

void solve()
{
    FOR(a, A) {
      int maximum = 0;
      FOR(b, a) {
        if (arr[b] < arr[a]) {
          maximum = max(maximum, DP[b]);
        }
      }
      DP[a] = maximum + 1;
      answer = max(DP[a], answer);
    }
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
  input();
  solve();
  print();
}