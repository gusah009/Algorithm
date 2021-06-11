#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

long long T, n, m;
long long A[1001], B[1001];
long long DPA[1001];
long long DPB[1001];
map<long long, long long> DPn;
map<long long, long long> DPm;
long long answer = 0;

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

  FOR(a, n) {
    FOR(b, a + 1) {
      if (b == 0) {
        if (DPn.find(DPA[a]) == DPn.end()) {
          DPn.insert(make_pair(DPA[a], 1));
        } else {
          DPn[DPA[a]]++;
        }
      }
      else {
        if (DPn.find(DPA[a] - DPA[b - 1]) == DPn.end()) {
          DPn.insert(make_pair(DPA[a] - DPA[b - 1], 1));
        } else {
          DPn[DPA[a] - DPA[b - 1]]++;
        }
      }
    }
  }

  FOR(c, m) {
    FOR(d, c + 1) {
      if (d == 0) {
        if (DPm.find(DPB[c]) == DPm.end()) {
          DPm.insert(make_pair(DPB[c], 1));
        } else {
          DPm[DPB[c]]++;
        }
        }
      else {
        auto it = DPm.find(DPB[c] - DPB[d - 1]);
        if (it == DPm.end()) {
          DPm.insert(make_pair(DPB[c] - DPB[d - 1], 1));
        } else {
          it->second++;
        }
      }
    }
  }

  for(auto iter = DPn.begin(); iter != DPn.end(); iter++){
    auto it = DPm.find(T - iter->first);
    if (it != DPm.end()) {
      answer += it->second * iter->second;
    }
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