#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

vector<int> answer;
int N;
bool isVisited[1000001] = {0};

void input()
{
  cin >> N;
}

void solve()
{
  queue<pair<int, vector<int> > > Q;
  vector<int> tmp;
  tmp.push_back(N);

  Q.push(make_pair(N, tmp));

  while(!Q.empty()) {
    int next = Q.front().first;
    // cout << next << ' ';
    vector<int> path = Q.front().second;
    Q.pop();

    if (next == 1) {
      answer = path;
      break;
    }

    if (isVisited[next]) continue;
    isVisited[next] = true;
    if (next % 3 == 0) {
      path.push_back(next / 3);
      Q.push(make_pair(next / 3, path));
      path.pop_back();
    }
    if (next % 2 == 0) {
      path.push_back(next / 2);
      Q.push(make_pair(next / 2, path));
      path.pop_back();
    }
    path.push_back(next - 1);
    Q.push(make_pair(next - 1, path));
  }
}

void print()
{
  cout << answer.size() - 1 << '\n';
  FOR(i, answer.size()) {
    cout << answer[i] << ' ';
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