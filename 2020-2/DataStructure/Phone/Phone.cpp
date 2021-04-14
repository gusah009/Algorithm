#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

vector<tuple<int, int, int>> P;
stack<tuple<int, int, int>> stk;
vector<int> ans;
int N;

void input()
{
  cin >> N;
  FOR(n, N) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    P.push_back(make_tuple(tmp1, tmp2, n+1));
  }
  sort(P.begin(), P.end());
}

void solve()
{
  for(int n = 0; n < N; n++) {
    while (!stk.empty() && get<0>(stk.top()) < get<0>(P[n]) && get<1>(stk.top()) > get<1>(P[n])) {
      stk.pop();
    }
    stk.push(P[n]);
  }
  while(!stk.empty()) {
    ans.push_back(get<2>(stk.top()));
    stk.pop();
  }
  sort(ans.begin(), ans.end());
}

void print()
{
  for(auto it = ans.begin(); it != ans.end(); it++) {
    cout << *it << "\n";
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