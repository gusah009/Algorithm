#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 987654321

int k;
vector< queue<int> > Q;
queue<int> answer;

void input()
{
  cin >> k;
  FOR(i, k) {
    queue<int> tmpq;
    int tmp;
    cin >> tmp;
    while(tmp != 0) {
      tmpq.push(tmp);
      cin >> tmp;
    }
    tmpq.push(0);
    Q.push_back(tmpq);
  }
}

void solve()
{
  int priority, index;
  while(priority != INF) {
    priority = INF;
    FOR(i, k) {
      if (Q[i].front() != 0) {
        if (priority > Q[i].front()) {
          priority = Q[i].front();
          index = i;
        }
      }
    }
    if (priority != INF) {
      Q[index].pop();
      answer.push(priority);
    }
  }
}

void print()
{
  while(!answer.empty()) {
    cout << answer.front() << "\n";
    answer.pop();
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