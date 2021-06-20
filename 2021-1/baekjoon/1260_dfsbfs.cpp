#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M, V;
set<int> edge[1001];
int isVisited[1001] = {0};

void input()
{
  cin >> N >> M >> V;
  FOR(m, M) {
    int v1, v2;
    cin >> v1 >> v2;
    edge[v1].insert(v2);
    edge[v2].insert(v1);
  }
}

void dfs(int n, int prev_n)
{
  if (isVisited[n]) {
    return;
  }
  cout << n << ' ';
  isVisited[n] = true;
  // if (edge[n].size() == 1) {
  // }
  for (auto it = edge[n].begin(); it != edge[n].end(); it++) {
    if (*it != prev_n) dfs(*it, n);
  }
}

void bfs(int n, int prev_n)
{
  queue<pair<int, int> > Q;
  Q.push(make_pair(n, prev_n));

  while(!Q.empty()) {
    int n = Q.front().first;
    int prev_n = Q.front().second;
    Q.pop();

    if (isVisited[n]) {
      continue;
    }
    cout << n << ' ';
    isVisited[n] = true;
    for (auto it = edge[n].begin(); it != edge[n].end(); it++) {
      if (*it != prev_n) Q.push(make_pair(*it, n));
    }
  }
}

void solve()
{
  dfs(V, -1);
  cout << '\n';
  fill(isVisited, isVisited + N + 1, 0);
  bfs(V, -1);
}

void print()
{

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