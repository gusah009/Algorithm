#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int answer = 0;
int board[1001][1001] = {0};
int moving[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
queue<pair<int, int>> ripeTomato1;

void input()
{
  FOR(n, 1001) { // 테두리 전부 -1로 
    FOR(m, 1001) {
      board[n][m] = -1;
    }
  }

  cin >> M >> N; // 원래 N >> M 인데 다 짜고 보니까 가로세로 바껴있어서
  // 그냥 cin >> M >> N 으로 바꿨습니다.
  FOR(n, N) {
    FOR(m, M) {
      cin >> board[n][m];
      if (board[n][m] == 1) {
        ripeTomato1.push(make_pair(n, m));
        // cout << ripeTomato1.back().first << " " << ripeTomato1.back().second << " ";
      }
    }
  }
}

void solve()
{
  bool cond = true; // 익은 토마토 후보가 1개라도 있으면
  while(cond) {
    queue<pair<int, int>> ripeTomato2;
    cond = false;
    while(!ripeTomato1.empty()) {
      int n = ripeTomato1.front().first;
      int m = ripeTomato1.front().second;
      ripeTomato1.pop();
      FOR(i, 4) { // 4방향 확인
        int mov_n = n + moving[i][0];
        int mov_m = m + moving[i][1];
        if (mov_n >= 0 && mov_m >= 0) { // 보드밖으로 벗어나면 안댐
          if (board[mov_n][mov_m] == 0) {
            cond = true; // 익은 토마토 후보가 1개라도 있으면
            board[mov_n][mov_m] = 1;
            ripeTomato2.push(make_pair(mov_n, mov_m)); // 1이 아니라 2에 저장해둠
          }
        }
      }
    }
    if (!cond) {
      break;
    }
    while(!ripeTomato2.empty()) { // 2 -> 1 저장해둔거 옮기기
      ripeTomato1.push(ripeTomato2.front());
      ripeTomato2.pop();
    }
    answer++;
  }
}

void print()
{
  FOR(n, N) {
    FOR(m, M) {
      if (board[n][m] == 0) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  cout << answer << "\n";
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