#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int X[1000001] = {0};
int sortedX[1000001] = {0};
unordered_map<int, int> mapping;

void input()
{
  cin >> N;
  FOR(n, N) {
    cin >> X[n];
    sortedX[n] = X[n];
  }
  sort(sortedX, sortedX + N); 
}

void solve()
{
  int prev = sortedX[0];
  mapping.insert(make_pair(prev, 0));
  int globalI = 1;
  for(int n = 1; n < N; n++) {
    if (prev != sortedX[n]) {
      prev = sortedX[n];
      mapping.insert(make_pair(prev, globalI++));
    }
  }
}

void print()
{
  FOR(n, N) {
    cout << mapping[X[n]] << ' ';
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