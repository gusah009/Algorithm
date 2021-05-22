#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, L, R;
int board[51][51][2] = {0};
pair<int, int> edge[51][4];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int answer = 0;

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
  bool currentBoard = false;
  bool flag = true;
  while(flag) {
    bool isVisited[51][51] = {0};
    flag = false;
    FOR(i, N) {
      FOR(j, N) {
        if(!isVisited[i][j]) {
          //i, j
          vector<pair<int, int> > path;
          queue<pair<int, int> > Q;

          Q.push(make_pair(i, j));
          path.push_back(make_pair(i, j));
          int total = board[i][j][currentBoard];
          isVisited[i][j] = true;
          while (!Q.empty()) { 
            int a = Q.front().first;
            int b = Q.front().second;
            Q.pop();
            FOR(d, 4) {
              int next_a = a + dir[d][0];
              int next_b = b + dir[d][1];
              if (next_a < 0 || next_a >= N) continue;
              if (next_b < 0 || next_b >= N) continue;
              if (isVisited[next_a][next_b]) continue;
              if (L <= abs(board[a][b][currentBoard] - board[next_a][next_b][currentBoard]) &&
                  abs(board[a][b][currentBoard] - board[next_a][next_b][currentBoard]) <= R){
                Q.push(make_pair(next_a, next_b));
                total += board[next_a][next_b][currentBoard];
                isVisited[next_a][next_b] = true;
                path.push_back(make_pair(next_a, next_b));
              }
            }
          }
          int population = total / path.size();
          FOR(p, path.size()) {
            int a = path[p].first;
            int b = path[p].second;
            board[a][b][!currentBoard] = population;
          }
          if (flag == false && path.size() != 1) flag = true;
        }
      }
    }
    if (flag) answer++;
    currentBoard = !currentBoard;
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