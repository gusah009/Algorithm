#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
// 사람, 파티
bool party[51][51] = {0};
queue<int> known;
bool isKnown[51] = {0};
bool cantLie[51] = {0};

void input()
{
  cin >> N >> M;
  int K;
  cin >> K;
  FOR(k, K) {
    int tmp;
    cin >> tmp;
    known.push(tmp);
    isKnown[tmp] = true;
  }
  FOR(m, M) {
    int tmp;
    cin >> tmp;
    FOR(i, tmp) {
      int pers;
      cin >> pers;
      party[pers][m] = true;
    }
  }
}

void solve()
{
  while (!known.empty()) {
    int virus = known.front();
    known.pop();
    FOR(m, M) {
      if(party[virus][m]) {
        cantLie[m] = true;
        FOR(n, N + 1) {
          if (party[n][m] && isKnown[n] == false) {
            isKnown[n] = true;
            known.push(n);
          }
        }
      }
    }
  }
}

void print()
{
  int answer = 0;
  FOR(m, M) {
    if (cantLie[m] == 0) {
      answer++;
    }
  }
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