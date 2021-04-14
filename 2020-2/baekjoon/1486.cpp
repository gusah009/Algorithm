/* Copyright 2020. 정현모. All rights reserved. */

/**
* @file 1486.cpp
* @brief 플로이드 와샬 공부 기념 1문제
* @author gusah009 (gusah009@naver.com)
**/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define INF 987654321
#define FORz(i,j) for (int i = 0; i < j; i++)
#define FORo(i,j) for (int i = 1; i <= j; i++)

int N, M, T, D;
int Mountain[27][27];
int adj[27][27][27][27];
int moving[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int answer = 0;

void create_adj()
{
  FORo(n, N) {
    FORo(m, M) {
      FORz(i, 4) {
        int move_y = n + moving[i][0];
        int move_x = m + moving[i][1];
        if (abs(Mountain[move_y][move_x] - Mountain[n][m]) <= T) {
          if (Mountain[n][m] < Mountain[move_y][move_x]) {
            adj[n][m][move_y][move_x] = (Mountain[move_y][move_x] - Mountain[n][m])*(Mountain[move_y][move_x] - Mountain[n][m]);
          } else {
            adj[n][m][move_y][move_x] = 1;
          }
        }
      }
    }
  }
}

void input()
{
  FORz(i, 27) {
    FORz(j, 27) {
      Mountain[i][j] = INF;
      FORz(n, 27) {
        FORz(m, 27) {
          if (n == i  && m == j) {
            adj[n][m][i][j] = 0;
          } else {
            adj[i][j][n][m] = INF;
          }
        }
      }
    }
  }
  
  cin >> N >> M >> T >> D;
  FORo(n1, N) {
    string tmp;
    cin >> tmp;
    FORo(m1, M) {
      if ('A' <= tmp[m1-1] && tmp[m1-1] <= 'Z') {
        Mountain[n1][m1] = tmp[m1-1] - 'A';
      } else {
        Mountain[n1][m1] = tmp[m1-1] - 'a' + 26;
      }
    }
  }
}

void solve()
{
  create_adj();
  FORo(k1, N) {
    FORo(k2, M) {
      FORo(n, N) {
        FORo(m, M) {
          FORo(i, N) {
            FORo(j, M) {
              adj[n][m][i][j] = min(adj[n][m][i][j], adj[n][m][k1][k2] + adj[k1][k2][i][j]);
            }
          }
        }
      }
    }
  }

  FORo(i, N) {
    FORo(j, M) {
      if (adj[1][1][i][j] + adj[i][j][1][1] <= D) {
        answer = max(answer, Mountain[i][j]);
      }
    }
  }
}

void print()
{
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