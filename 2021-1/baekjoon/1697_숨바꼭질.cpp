#include <iostream>
#include <queue>
#include <assert.h> 
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, K;
int DP[300001] = {0};

void input()
{
  cin >> N >> K;
  FOR(i, 300001) {
    DP[i] = INF;
  }
}


void solve()
{
  if (N == K) {

  }
  queue<pair<int, int> > Q;
  Q.push(make_pair(N, 0));

  while(!Q.empty()) {
    int next = Q.front().first;
    int t = Q.front().second;
    Q.pop();
    
    if (DP[next] >= t) {
      DP[next] = t;
      // cout << next << '\n';
      if (next < 100001) {
        Q.push(make_pair(next + 1, t + 1));
      }
      if (next > 0) {
        Q.push(make_pair(next - 1, t + 1));
      }
      if (next * 2 < 100001) {
        Q.push(make_pair(next * 2, t + 1));
      }
    }
  }
}

void print()
{
  // ofstream out("test.txt");
  // FOR(i, 200000) {
  //   out << i << ':' << DP[i] << '\n';
  // }
  // assert (DP[K] == INF);
  cout << DP[K] << '\n';
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