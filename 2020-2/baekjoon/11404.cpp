/* Copyright 2020. 정현모. All rights reserved. */

/**
* @file 11404.cpp
* @brief 플로이드 와샬 기본문제
* @brief 2020.09.19
* @author gusah009 (gusah009@naver.com)
**/

#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321
#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int adj[100][100];

void input()
{
  FOR(i, 100) {
    FOR(j ,100) {
      if (i == j) {
        adj[i][j] = 0;
      } else {
        adj[i][j] = INF;
      }
    }
  }

  cin >> N >> M;
  FOR(m, M) {
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    if (t3 < adj[t1-1][t2-1]) {
      adj[t1-1][t2-1] = t3;
    }
  }
}

void solve()
{
  FOR(k, N)
    FOR(i, N)
      FOR(j, N)
        adj[i][j] = adj[i][j] < (adj[i][k] + adj[k][j]) ? adj[i][j] : (adj[i][k] + adj[k][j]);
}

void print()
{
  FOR(i, N) {
    FOR(j, N)
      cout << (adj[i][j] == INF ? 0 : adj[i][j]) << " ";
    cout << "\n";  
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