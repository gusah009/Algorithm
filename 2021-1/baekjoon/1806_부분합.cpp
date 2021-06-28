#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, S;
int arr[100001];
int answer = INF;

void input()
{
  cin >> N >> S;
  FOR(n, N) {
    cin >> arr[n];
  }
}

void solve()
{
  int i = 0, j = 0;
  int sum = 0;
  while(j != N) {
    while(i < j && sum >= S) {
      // cout << i << ' ' << j << '\n';
      sum -= arr[i];
      answer = min(answer, j - i);
      i++;
    }
    sum += arr[j];
    j++;
  }
  while(i < j && sum >= S) {
    // cout << i << ' ' << j << '\n';
    sum -= arr[i];
    answer = min(answer, j - i);
    i++;
  }
}

void print()
{
  cout << (answer == INF ? 0 : answer) << '\n';
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