#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
tuple<int, int, int> ESC[300001];
int DP[600001];
int maximum = 0;

void input()
{
  set<int> s;
  unordered_map<int, int> m;

  cin >> N;
  FOR(n, N) {
    int S, E, C;
    cin >> S >> E >> C;
    s.insert(E);
    s.insert(S);
    ESC[n] = make_tuple(E, S, C);
  }
  sort(&ESC[0], &ESC[N]);

  for(auto iter = s.begin(); iter != s.end(); iter++){
    m[*iter] = maximum++;
  }

  FOR(n, N) {
    int S, E;
    E = get<0>(ESC[n]);
    S = get<1>(ESC[n]);
    ESC[n] = make_tuple(m[E], m[S], get<2>(ESC[n]));
  }
}

void solve()
{
  DP[0] = 0;
  int index = 0;

  for(int n = 1; n <= maximum; n++) {
    DP[n] = DP[n - 1];
    while (n == get<0>(ESC[index])) {
      if (get<1>(ESC[index]) != 0) {
        DP[n] = max(DP[get<1>(ESC[index]) - 1] + get<2>(ESC[index]), DP[n]);
      } else {
        DP[n] = max(get<2>(ESC[index]), DP[n]);
      }
      index++;
    }
  }
}

void print()
{
  cout << DP[maximum] << "\n";
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