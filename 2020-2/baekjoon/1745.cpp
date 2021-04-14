/* Copyright 2020. 정현모. All rights reserved. */

/**
* @file 1745.cpp
* @brief 플로이드-와샬 공부기념 문제 (플레티넘1)
* @brief 2020.09.19
* @author gusah009 (gusah009@naver.com)
**/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long int
#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 987654321987654321

ll F, P;
ll curr[200] = {0}, poss[200] = {0};
ll adj[200][200];
priority_queue<pair<ll, int> > new_adj[200];

void input()
{
  FOR(i, 200) {
    FOR(j, 200) {
      if (i == j)
        adj[i][j] = 0;
      else
        adj[i][j] = MAX;;
    }
  }

  cin >> F >> P;
  FOR(f, F) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    tmp1 > tmp2 ? curr[f] = tmp1 - tmp2 : poss[f] = tmp2 - tmp1;
  }
  FOR(p, P) {
    ll tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    if (adj[tmp1 - 1][tmp2 - 1] > tmp3)
      adj[tmp1 - 1][tmp2 - 1] = tmp3;
    if (adj[tmp2 - 1][tmp1 - 1] > tmp3)
      adj[tmp2 - 1][tmp1 - 1] = tmp3;
  }
}

void solve()
{
  // 플로이드 - 와샬
  FOR(k, F) {
    FOR(i, F) {
      FOR(j, F) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }

  // 오름차순으로 정렬
  FOR(i, F) {
    if(curr[i] != 0) {
      FOR(j, F) {
        if (poss[j] != 0) {
          new_adj[i].push(make_pair(adj[i][j], j));
        }
      }
    }
  }

  FOR(i, F) {
    while(new_adj[i].size() != 0) {
      cout << "i: " << i << " " << new_adj[i].top().first << " " << new_adj[i].top().second << "\n";
      new_adj[i].pop();
    }
  }

  // 더 급한 순 + 그리디로
  // FOR(i, F) {
  //   if (curr[i] != 0) {
  //     ll val = new_adj[i].top().first;
  //     ll num = new_adj[i].top().second;
  //     new_adj[i].pop();
  //     ll diff = new_adj[i].top().first - val;
  //     FOR(k, F) {
  //       if (num == new_adj[k].top().second) {
  //         pair<ll, int> tmp = new_adj[k].top();
  //         new_adj[k].pop();
  //         // 얘가 더 급함
  //         if (diff < new_adj[k].top().first - tmp.first) {
  //           val = tmp.first;
  //           diff = new_adj[k].top().first - tmp.first;
  //         }
  //         new_adj[k].push(tmp);
  //       }
  //     }
  //   }
  // }
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