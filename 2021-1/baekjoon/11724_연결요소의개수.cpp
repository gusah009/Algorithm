#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
vector<int> edge[1001];
bool isVisited[1001] = {0};
bool chk;
int answer = 0;

void input()
{
  cin >> N >> M;
  FOR(m, M) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
}

void visitDFS(int n) {
  if (isVisited[n]) {
    return;
  }
  isVisited[n] = true;

  FOR(i, edge[n].size()) {
    visitDFS(edge[n][i]);
  }
}

void solve()
{
  for(int n = 1; n < N + 1; n++) {
    if (!isVisited[n]) {
      visitDFS(n);
      answer++;
    }
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