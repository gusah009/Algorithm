#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N;
int W[17][17] = {0};
int DP[17][65537] = {0};
int endPoint = -1;
int allVisited;

void input()
{
  cin >> N;
  allVisited = pow(2, N) - 1;
  FOR(i, N) {
    FOR(j, N) {
      cin >> W[i][j];
    }
  }
  fill(DP[0], DP[17], INF);
}

void DFS(int n, int visited, int w)
{
  if ((visited >> n) & 1) {
    return;
  }

  visited |= (1 << n);

  if (n == endPoint) {
    if (visited != allVisited) {
      return;
    }
  }

  if (DP[n][visited] > w) {
    DP[n][visited] = w;
    pair<int, int> temp[N];
    FOR(i, N) {
      temp[i] = make_pair(W[n][i], i);
    }
    sort(temp, temp + N);
    FOR(i, N) {
      if (temp[i].first != 0) {
        DFS(temp[i].second, visited, w + temp[i].first);
      }
    }
  }

}

void solve()
{
  endPoint = 0;
  FOR(i, N) {
    if (W[0][i] != 0) {
      DFS(i, 0, W[0][i]);
    }
  }
}

void print()
{
  int answer = INF;
  FOR(n, N) {
    answer = min(answer, DP[n][allVisited]);
  }
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