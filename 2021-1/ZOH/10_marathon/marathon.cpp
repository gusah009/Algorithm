#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321

int N, M;
vector<pair<int, int> > V[26];
bool isPassed[26] = {0};
vector<string> answer;
int dist[30];
struct Edge {
  int s;
  int e;
  int val;
  Edge(int a, int b, int c) {
    s = a;
    e = b;
    val = c;
  }
};
vector<Edge> Ed;

void input()
{
  ifstream in("marathon.inp");
  in >> N >> M;
  FOR(m, M) {
    char a, b;
    int w;
    in >> a >> b >> w;
    Ed.push_back(Edge(a - 'a', b - 'a', w));
    Ed.push_back(Edge(b - 'a', a - 'a', w));
    V[a - 'a'].push_back(make_pair(b - 'a', w));
    V[b - 'a'].push_back(make_pair(a - 'a', w));
  }
  in.close();

  FOR(i, 26) {
    dist[i] = INF;
    sort(V[i].begin(), V[i].end());
  }
  dist[0] = 0;
}

bool comp(string a, string b)
{
  if (a.size() == b.size()) {
    return a < b;
  } else {
    return a.size() > b.size();
  }
}

void DFS(int a, int prev_a, int weight, string path) {
  if (weight == 42 && a == 0) {
    answer.push_back(path);
    return;
  }
  if (weight > 42) {
    return;
  }
  if (weight + dist[a] > 42) {
    return;
  }

  FOR(i, V[a].size()) {
    int nextV = V[a][i].first;
    if (!isPassed[nextV]) {
      if(nextV != prev_a) {
        path.push_back(nextV + 'a');
        isPassed[nextV] = true;
        DFS(nextV, a, weight + V[a][i].second, path);
        path.pop_back();
        isPassed[nextV] = false;
      }
    }
  }

  return;
}

void solve()
{
  for (int i = 0; i < N * 2; i++) {
    for (int j = 0; j < Ed.size(); j++) {
      int s = Ed[j].s;
      int e = Ed[j].e;
      int w = Ed[j].val;
      if (dist[s] != INF && dist[s] + w < dist[e]) {
          dist[e] = dist[s] + w;
      }
    }
  }
  // FOR(n, N) {
  //   cout << (n + 'a') << " " << dist[n] << '\n';
  // }

  string tmp = "";
  DFS(0, -1, 0, tmp);

  sort(answer.begin(), answer.end(), comp);
  // cout << answer.size() << '\n';
  // FOR(i, answer.size()) {
  //   cout << answer[i].size() << ' ';
  //   cout << answer[i] << '\n';
  // }
}

void print()
{
  ofstream out("marathon.out");
  if (answer.size() == 0) {
    out << "None\n";
  } else {
    out << answer[0].size() << '\n';
    out << "a ";
    FOR(i, answer[0].size() - 1) {
      out << answer[0][i] << ' ';
    }
  }
  out.close();
}

int main()
{
  input();
  solve();
  print();

  return 0;
}