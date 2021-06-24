#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int arr[100001] = {0};
int sum, answer[2];

void input()
{
  cin >> N;
  FOR(n, N) {
    cin >> arr[n];
  }
}

void solve()
{
  int i = 0;
  int j = N - 1;
  bool ijflag = true;
  sum = abs(arr[i] + arr[j]);
  answer[0] = arr[i];
  answer[1] = arr[j];

  while(abs(i - j) > 1) {
    bool flag = true;
    // cout << sum << ' ' << abs(arr[i] + arr[j]) << ' ' << i << ' ' << j << '\n';
    // cout <<  << '\n';
    if (abs(arr[i + 1] + arr[j]) < abs(arr[i] + arr[j - 1])) {
      if (sum > abs(arr[i + 1] + arr[j])) {
        sum = abs(arr[i + 1] + arr[j]);
        answer[0] = arr[i + 1];
        answer[1] = arr[j];
      } 
      i++;
    } else {
      if (sum > abs(arr[i] + arr[j - 1])) {
        sum = abs(arr[i] + arr[j - 1]);
        answer[0] = arr[i];
        answer[1] = arr[j - 1];
      }
      j--;
    }
  }
}

void print()
{
  cout << answer[0] << ' ' << answer[1] << '\n';
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