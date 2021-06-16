#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
vector<pair<int, int> > Q;
int answer = 0;

void input()
{
  cin >> N;
}

void queen(int depth) {
  if (depth == N) {
    answer++;
  }

  FOR(i, N) {
    bool flag = true;
    FOR(q, Q.size()) {
      if (Q[q].second == i || abs(Q[q].second - i) == abs(Q[q].first - depth)) {
        flag = false;
        break;
      }
    }
    if (flag) {
      Q.push_back(make_pair(depth, i));
      queen(depth + 1);
      Q.pop_back();
    }
  }
}

void solve()
{
  queen(0);
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