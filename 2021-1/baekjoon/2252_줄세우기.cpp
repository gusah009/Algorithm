#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, M;
int dist[32001];
bool isTallest[32001];
vector<int> student[32001];

void input()
{
  fill(isTallest, isTallest + 32001, true);
  cin >> N >> M;
  FOR(m, M) {
    int big, small;
    cin >> big >> small;
    student[big].push_back(small);
    isTallest[small] = false;
  }
  fill(dist, dist + 32001, -1);
}

void solve()
{
  for(int n = 1; n < N + 1; n++) {
    if(isTallest[n]) {
      priority_queue<pair<int, int> > PQ;
      PQ.push(make_pair(0, n));
      dist[n] = 0;

      while(!PQ.empty()) {
        int v = PQ.top().second;
        int w = PQ.top().first;
        PQ.pop();

        if (dist[v] > w) continue;
        FOR(i, student[v].size()) {
          int next_v = student[v][i];
          if (dist[next_v] < w + 1) {
            dist[next_v] = w + 1;
            PQ.push(make_pair(dist[next_v], next_v));
          }
        }
      }
    }
  }
}

void print()
{
  set<pair<int, int> > order;
  for(int n = 1; n < N + 1; n++) {
    order.insert(make_pair(dist[n], n));
    // cout << n << ':' << dist[n] << '\n';
  }

  for(auto iter = order.begin(); iter != order.end(); iter++){
      cout << iter->second << " " ;
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