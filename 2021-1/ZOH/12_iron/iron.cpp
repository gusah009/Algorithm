#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX 26
#define START 0

int N, M;
int edge[MAX][MAX] = {0};
int dist[MAX] = {0};
vector<vector<int> > answer;

void input()
{

  ifstream in("iron.inp");
  in >> N >> M;
  FOR(m, M) {
    char v1, v2;
    int w;
    in >> v1 >> v2 >> w;
    edge[v1 - 'a'][v2 - 'a'] = w;
    edge[v2 - 'a'][v1 - 'a'] = w;
  }
}


void solve()
{
  priority_queue<pair<int, int> > PQ;
  PQ.push(make_pair(0, START));

  while (!PQ.empty()) {
    int w = PQ.top().first;
    int v = PQ.top().second;
    PQ.pop();

    
  }
}

void print()
{
  ofstream out("iron.out");
  out << "None\n";
  out.close();
}

  int main()
  {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    print();
  }