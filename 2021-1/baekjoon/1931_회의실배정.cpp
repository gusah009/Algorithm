#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
set<int> tmp;
unordered_map<int, int> mapping;
vector<pair<int, int> > se;
int DP[200001] = {0};
int answer = 0;

void input()
{
  cin >> N;
  FOR(n, N) {
    int s, e;
    cin >> s >> e;
    tmp.insert(s);
    tmp.insert(e);
    se.push_back(make_pair(e, s));
  }
}

void solve()
{
  int i = 1;
  for (auto it = tmp.begin(); it != tmp.end(); it++) {
    // cout << *it << '\n';
    mapping[*it] = i++;
  }
  FOR(n, N) {
    se[n].first = mapping[se[n].first];
    se[n].second = mapping[se[n].second];
  }
  sort(se.begin(), se.end());

  int j = 0;
  for(int n = 1; n < i; n++) {
    DP[n] = DP[n - 1];
    if (j == N) break;
    while (se[j].first == n) {
      DP[n] = max(DP[n], DP[se[j].second] + 1);
      answer = max(DP[n], answer);
      // cout << se[j].first << ' ' << se[j].second << ' ' << n << ' ' << DP[n] << '\n';
      j++;
      if (j == N) break;
    }
    // if (DP[n] < DP[n - 1]) DP[n] = DP[n - 1];
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