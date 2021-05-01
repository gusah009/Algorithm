#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N, M;
vector<pair<int, int> > V[26];
bool isPassed[26] = {0};
vector<string> answer;

void input()
{
  ifstream in("marathon.inp");
  in >> N >> M;
  FOR(m, M) {
    char a, b;
    int w;
    in >> a >> b >> w;
    V[a - 'a'].push_back(make_pair(b - 'a', w));
    V[b - 'a'].push_back(make_pair(a - 'a', w));
  }
  in.close();

  FOR(i, 26) {
    sort(V[i].begin(), V[i].end());
  }
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
  if (weight >= 42 || a == 0) {
    if (weight == 42 && a == 0) {
      answer.push_back(path);
    }
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
  string tmp = "";
  DFS(0, -1, 0, tmp);

  sort(answer.begin(), answer.end(), comp);
  cout << answer.size() << '\n';
  FOR(i, answer.size()) {
    cout << answer[i].size() << ' ';
    cout << answer[i] << '\n';
  }
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