#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
set<string> db;
priority_queue<string, vector<string>, greater<string> > ans;

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    string tmp;
    cin >> tmp;
    db.insert(tmp);
  }
  FOR(m, M) {
    string tmp;
    cin >> tmp;
    if (db.find(tmp) != db.end()) {
      ans.push(tmp);
    }
  }
}

void solve()
{
    
}

void print()
{
  cout << ans.size() << '\n';
  while(!ans.empty()) {
    cout << ans.top() << '\n';
    ans.pop();
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