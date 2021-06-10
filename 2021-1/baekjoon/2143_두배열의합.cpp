#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, n, m;
long long A[1001], B[1001];
long long DPA[1001];
long long DPB[1001];
multiset<long long> DPn;
multiset<long long> DPm;
long long answer = 0;

typedef std::multiset<long long>::iterator It;

void input()
{
  cin >> T;
  cin >> n;
  FOR(i, n) {
    cin >> A[i];
  }
  cin >> m;
  FOR(i, m) {
    cin >> B[i];
  }
}

void solve()
{
  DPA[0] = A[0];
  for(long long i = 1; i < n; i++) {
    DPA[i] = DPA[i - 1] + A[i];
  }
  DPB[0] = B[0];
  for(long long i = 1; i < m; i++) {
    DPB[i] = DPB[i - 1] + B[i];
  }

  int X = 0;
  FOR(a, n) {
    FOR(b, a + 1) {
      if (b == 0) DPn.insert(DPA[a]);
      else DPn.insert(DPA[a] - DPA[b - 1]);
    }
  }

  int Y = 0;
  FOR(c, m) {
    FOR(d, c + 1) {
      if (d == 0) DPm.insert(DPB[c]);
      else DPm.insert(DPB[c] - DPB[d - 1]);
    }
  }

  // cout << "!!: " << DPn.size() << '\n';
  for(auto iter = DPn.begin(); iter != DPn.end(); iter++){
    // cout << *iter << '\n';
    pair<It,It> ret = DPm.equal_range(T - *iter);
    answer += distance(ret.first, ret.second);
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