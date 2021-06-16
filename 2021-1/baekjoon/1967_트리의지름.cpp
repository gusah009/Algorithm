#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
vector< pair<int, int> > edge[10001];
pair<int, int> answer;

void input()
{
  cin >> N;
  FOR(n, N - 1) {
    int parent, child, weight;
    cin >> parent >> child >> weight;
    edge[parent].push_back(make_pair(child, weight));
    edge[child].push_back(make_pair(parent, weight));
  }
  answer.second = 0;
}

void DFS(int n, int prev_n, int w)
{
  if (edge[n].size() == 1) {
    // cout << "n: " << n << '\n';
    if (answer.second < w) {
      answer.second = w;
      answer.first = n;
    }
  }

  FOR(i, edge[n].size()) {
    if (edge[n][i].first != prev_n) DFS(edge[n][i].first, n, w + edge[n][i].second);
  }
}

void solve()
{
  DFS(1, -1, 0);
  DFS(answer.first, -1, 0);
}

void print()
{
  cout << answer.second << '\n';
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