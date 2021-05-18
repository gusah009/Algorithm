#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX 26
#define START 0

int N, M;
int edge[MAX][MAX] = {0};
int dist[MAX] = {0};
pair<int, vector<int> > answer;

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
  // weight, vertex, isVisted
  priority_queue<pair<int, pair<int, vector<int> > > > PQ;
  vector<int> tmp;
  PQ.push(make_pair(0, make_pair(START, tmp)));

  while (!PQ.empty()) {
    int curr_w = PQ.top().first;
    int curr_v = PQ.top().second.first;
    vector<int> isVisited = PQ.top().second.second;
    PQ.pop();

    if (curr_v == 0) {
      if (curr_w != 0) {
        if (curr_w > answer.first) {
          answer = make_pair(curr_w, isVisited);
        } else if (curr_w == answer.first) {
          if (answer.second.size() < isVisited.size()) {
            answer = make_pair(curr_w, isVisited);
          } else if (answer.second.size() == isVisited.size()) {
            if (answer.second > isVisited) {
              answer = make_pair(curr_w, isVisited);
            }
          }
        }
        // cout << "ans: " << curr_w << ' ' << curr_v << "\n";
        continue;
      }
    }

    FOR(i, MAX) {
      if (edge[curr_v][i]) {
        if (find(isVisited.begin(), isVisited.end(), i) == isVisited.end()) {
          int next_w = edge[curr_v][i];
          int next_v = i;

          // if (dist[next_v] < curr_w + next_w) {
          //   dist[next_v] = curr_w + next_w;
          // }
          // cout << curr_w << ' ' << curr_v << ' ' << i << "\n";
          vector<int> nowVisited(isVisited.size());
          copy(isVisited.begin(), isVisited.end(), nowVisited.begin());
          nowVisited.push_back(next_v);
          PQ.push(make_pair(curr_w + next_w, make_pair(next_v, nowVisited)));
        }
      }
    }
  }
}

void print()
{
  // cout << answer.first << '\n';
  // cout << 'a' << ' ';
  // FOR(j, answer.second.size() - 1) {
  //   cout << char((answer.second)[j] + 'a') << ' ';
  // }
  // cout << '\n';
  ofstream out("iron.out");
  out << answer.first << '\n';
  out << 'a' << ' ';
  FOR(j, answer.second.size() - 1) {
    out << char((answer.second)[j] + 'a') << ' ';
  }
  out << '\n';
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