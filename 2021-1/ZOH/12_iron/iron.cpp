#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX 26
#define START 0

int N, M;
int edge[MAX][MAX] = {0};
int dist[(1 << 26)] = {0};
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
  // weight, vertex, isVisted, visitPath
  queue<pair<pair<int, int>, pair<int, vector<int> > > > Q;
  vector<int> tmp;
  Q.push(make_pair(make_pair(0, START), make_pair(0, tmp)));

  while (!Q.empty()) {
    int curr_w = Q.front().first.first;
    int curr_v = Q.front().first.second;
    int isVisited = Q.front().second.first;
    vector<int> visitPath = Q.front().second.second;
    Q.pop();

    if (curr_v == 0) {
      if (curr_w != 0) {
        if (curr_w > answer.first) {
          answer = make_pair(curr_w, visitPath);
        } else if (curr_w == answer.first) {
          if (answer.second.size() < visitPath.size()) {
            answer = make_pair(curr_w, visitPath);
          } else if (answer.second.size() == visitPath.size()) {
            if (answer.second > visitPath) {
              answer = make_pair(curr_w, visitPath);
            }
          }
        }
        // cout << "ans: " << curr_w << ' ' << curr_v << "\n";
        continue;
      }
    }

    FOR(i, MAX) {
      if (edge[curr_v][i]) {
        if (find(visitPath.begin(), visitPath.end(), i) == visitPath.end()) {
          int next_w = edge[curr_v][i];
          int next_v = i;
          int nextVisited = isVisited + (1 << i);

          if (dist[nextVisited] <= curr_w + next_w) {
            dist[nextVisited] = curr_w + next_w;
            // cout << curr_w << ' ' << curr_v << ' ' << i << "\n";
            vector<int> currPath(visitPath.size());
            copy(visitPath.begin(), visitPath.end(), currPath.begin());
            currPath.push_back(next_v);
            Q.push(make_pair(make_pair(curr_w + next_w, next_v), make_pair(nextVisited, currPath)));
          }
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