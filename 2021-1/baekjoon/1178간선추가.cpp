#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int V, E;
vector<int> edge[1001];
priority_queue<int> graphs;
bool isVisited[1001] = {0};
int answer = 0;

void input()
{
  cin >> V >> E;
  FOR(e, E) {
    int v1, v2;
    cin >> v1 >> v2;
    edge[v2].push_back(v1);
    edge[v1].push_back(v2);
  }
}

int BFS(int v)
{
  queue<int> vertex;
  vertex.push(v);
  isVisited[v] = true;
  int oddCount = 0;

  while(!vertex.empty()) {
    int curr_v = vertex.front();
    vertex.pop();

    if (edge[curr_v].size() % 2) {
      oddCount++;
    }
    FOR(i, edge[curr_v].size()) {
      int next_v = edge[curr_v][i];
      if (!isVisited[next_v]) {
        vertex.push(next_v);
        isVisited[next_v] = true;
      }
    }
  }
  return oddCount;
}

void solve()
{
  for(int v = 1; v < V + 1; v++) {
    if (!isVisited[v]) {
      int oddCount = BFS(v);
      graphs.push(oddCount);
    }
  }

  if (graphs.size() == 1) {
    if (graphs.top() <= 0) {
      answer = 0;
    } else {
      answer = (graphs.top() - 2) / 2;
    }
  } else {
    int total = 0;
    int curr = 0;
    int next = graphs.top();
    // cout << graphs.top() << '\n';
    graphs.pop();
    if (next <= 0) {
      total -= 2;
    }
    while(!graphs.empty()) {
      // cout << graphs.top() << '\n';
      curr = next;
      next = graphs.top();
      graphs.pop();
      curr <= 0 ? curr++ : curr--;
      next <= 0 ? next++ : next--;
      total += curr;
      answer++;
    }
    total += next;
    answer += (total <= 0 ? 0 : (total - 2) / 2);
    // cout << total << '\n';
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