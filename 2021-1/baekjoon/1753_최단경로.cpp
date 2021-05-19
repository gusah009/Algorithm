#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int V, E, START;
// pair<가중치, 도착지>
vector<pair<int, int> > board[20001];
int dist[20001];

void input()
{
  cin >> V >> E;
  cin >> START;
  FOR(e, E) {
    int src, dst, weight;
    cin >> src >> dst >> weight;
    board[src].push_back(make_pair(weight, dst));
  }
  fill(dist, dist + 20001, INF);
}

void solve()
{
  priority_queue<pair<int, int> > PQ;
  PQ.push(make_pair(0, START));
  dist[START] = 0;

  while(!PQ.empty()) {
    int v = PQ.top().second;
    int w = -PQ.top().first;
    PQ.pop();

    if (dist[v] < w) continue;
    FOR(i, board[v].size()) {
      int next_v = board[v][i].second;
      int next_w = board[v][i].first;
      if (dist[next_v] > w + next_w) {
        dist[next_v] = w + next_w;
        PQ.push(make_pair(-dist[next_v], next_v));
      }
    }
  }
}

void print()
{
  for(int v = 1; v < V + 1; v++) {
    if (dist[v] == INF) cout << "INF\n";
    else cout << dist[v] << '\n';
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