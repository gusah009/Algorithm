#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

bool chk;
int V, E;
pair<int, pair<int, int> > path[100001];
int parent[100001];
int answer = 0;

int find(int u)
{
  if (u == parent[u]) {
    return u;
  }
  return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u == v) return;

  parent[u] = v;
  chk = true;
}

void input()
{
  cin >> V >> E;
  FOR(e, E) {
    int src, dst, w;
    cin >> src >> dst >> w;
    path[e] = make_pair(w, make_pair(src, dst));
  }
  sort(path, path + E);
}

void solve()
{
  FOR(v, V + 1) parent[v] = v;
  FOR(e, E) {
    chk = false;
    merge(path[e].second.first, path[e].second.second);

    if(chk) {
      answer += path[e].first;
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