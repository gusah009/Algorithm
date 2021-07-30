#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int T, W, H, w, h;
int x1, y1, x2, y2;
int answer;

void input()
{
  cin >> W >> H;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> w >> h;
  answer = INF;
}

void solve()
{
  int dw1, dh1, dw2, dh2;
  dw1 = x1;
  dh1 = y1;
  dw2 = W - x2;
  dh2 = H - y2;

  // answer = min(min(h - dh1, h - dh2), min(w - dw1, w - dw2));
  if (h - dh1 >= 0) {
    if (h - dh1 <= dh2) {
      answer = min(answer, h - dh1);
    }
  } else {
    answer = 0;
    return;
  }
  if (h - dh2 >= 0) {
    if (h - dh2 <= dh1) {
      answer = min(answer, h - dh2);
    }
  } else {
    answer = 0;
    return;
  }
  if (w - dw1 >= 0) {
    if (w - dw1 <= dw2) {
      answer = min(answer, w - dw1);
    }
  } else {
    answer = 0;
    return;
  }
  if (w - dw2 >= 0) {
    if (w - dw2 <= dw1) {
      answer = min(answer, w - dw2);
    }
  } else {
    answer = 0;
    return;
  }
  
//  if (answer )
}

void print()
{
  cout << (answer == INF ? -1 : answer) << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  FOR(t, T) {
    input();
    solve();
    print();
  }
}