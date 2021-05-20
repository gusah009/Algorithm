#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, L, R;
int board[51][51][2];
pair<int, int> edge[51][4];

void input()
{
  cin >> N >> L >> R;
  FOR(i, N) {
    FOR(j, N) {
      cin >> board[i][j][0];
    }
  }
}

void solve()
{
  FOR(n, N) {
    vector<pair<int, int> > path;
    queue<int> Q;
    int total = 0;

    Q.push(0);
    while (!Q.empty()) {
      
    }
  }
}

void print()
{

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