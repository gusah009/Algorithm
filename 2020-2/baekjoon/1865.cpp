/* Copyright (C) gusah009 <gusah009@naver.com> */
 
/**
 * @file 1865.cpp
 * @brief 벨만포드 공부 기념 1문제
 * @author gusah009 (gusah009@naver.com)
 **/
#include <iostream>
#include <vector>
#include <tuple>

#define FOR(i, j) for (int i = 1; i <= j; i++)
#define INF 1987654321
#define START 1
using namespace std;

int TC, N, M, W;
vector<pair<int, int> > SET[501];
int dist[501];

void solve()
{
  cin >> TC;
  FOR(tc, TC) {
    cin >> N >> M >> W;
    FOR(m, M) {
      int tmp1, tmp2, tmp3;
      cin >> tmp1 >> tmp2 >> tmp3;
      SET[tmp1].push_back(make_pair(tmp3, tmp2));
      SET[tmp2].push_back(make_pair(tmp3, tmp1));
    }
    FOR(w, W) {
      int tmp1, tmp2, tmp3;
      cin >> tmp1 >> tmp2 >> tmp3;
      SET[tmp1].push_back(make_pair(-tmp3, tmp2));
    }
    
    FOR(n, N) {
      dist[n] = INF;
    }
    dist[START] = 0;
    bool check;
    FOR(n, N) {
      check = false;
      FOR(here, N) {
        for (int i = 0; i < SET[here].size(); i++) {
          int there = SET[here][i].second;
          int cost = SET[here][i].first;
          // cout << here << " : " << there << " " << dist[there] << "\n";
          if (dist[there] > dist[here] + cost) {
            dist[there] = dist[here] + cost;
            // cout << here << " : " << there << " " << dist[there] << "\n";
            check = true;
          }
        }
      }
      if(!check) break;
    }
    if (check) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
    FOR(n, N) {
      SET[n].clear();
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}