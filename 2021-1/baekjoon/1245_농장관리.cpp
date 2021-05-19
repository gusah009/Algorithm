#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321

int N, M;
int board[101][71];
int answer = 0;
int dir[8][2] = {
                  { 1, 0}, { 1,  1}, {0,  1}, {-1,  1}, 
                  {-1, 0}, {-1, -1}, {0, -1}, { 1, -1}
                };

void input()
{
  cin >> N >> M;
  FOR(n, N)
  {
    FOR(m, M)
    {
      cin >> board[n][m];
    }
  }
}

bool checkBong(int n, int m, vector<pair<int, int>> path)
{
  FOR(i, 8) {
    int next_n = n + dir[i][0];
    int next_m = m + dir[i][1];
    if (find(path.begin(), path.end(), make_pair(next_n, next_m)) != path.end()) continue;
    if (0 > next_n || next_n >= N) continue;
    if (0 > next_m || next_m >= M) continue;
    if (board[n][m] < board[next_n][next_m]) return false;
    if (board[n][m] == board[next_n][next_m]) {
      path.push_back(make_pair(next_n, next_m));
      if (!checkBong(next_n, next_m, path)) {
        return false;
      }
      path.pop_back();
    }
  }
  return true;
}

void setBong(int n, int m, vector<pair<int, int>> path)
{
  board[n][m] = INF;
  FOR(i, 8) {
    int next_n = n + dir[i][0];
    int next_m = m + dir[i][1];
    if (find(path.begin(), path.end(), make_pair(next_n, next_m)) != path.end()) continue;
    if (0 > next_n || next_n >= N) continue;
    if (0 > next_m || next_m >= M) continue;
    if (board[n][m] == board[next_n][next_m]) {
      path.push_back(make_pair(next_n, next_m));
      setBong(next_n, next_m, path);
      path.pop_back();
    }
  }
}
void solve()
{
  FOR(n, N)
  {
    FOR(m, M)
    {
      if (board[n][m] != INF) {
        vector<pair<int, int>> tmp;
        tmp.push_back(make_pair(n, m));
        if (checkBong(n, m, tmp))
        {
          setBong(n, m, tmp);
          // cout << n << ',' << m << '\n';
          answer++;
        }
      }
    }
  }
}

void print()
{
  cout << answer << '\n';
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}