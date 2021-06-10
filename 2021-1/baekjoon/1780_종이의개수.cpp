#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int board[2188][2188] = {0};
int answer[3] = {0};

void input()
{
  cin >> N;
  FOR(i, N) {
    FOR(j, N) {
      cin >> board[i][j];
    }
  }
}

int three(int N, int a, int b)
{
  if (N == 1) {
    return board[a][b];
  }

  int result[9];
  FOR(i, 9) {
    result[i] = -3;
  }
  bool flag = false;
  FOR(i, 3) {
    FOR(j, 3) {
      result[3 * i + j] = three(N / 3, a + N / 3 * i, b + N / 3 * j);
      // cout << result[3 * i + j] << '\n';
      if ((i != 0 || j != 0) && result[3 * i + j] != result[3 * i + j - 1]) {
        flag = true;
      }
    }
  }
  // cout << a << ' ' << b << " flag: " << flag << '\n';
  // FOR(i, 9) {
  //   cout << result[i] << ' ';
  // }
  // cout << '\n';
  if (flag) {
    FOR(i, 9) {
      if (result[i] != -2) answer[result[i] + 1]++;
    }
    return -2;
  } else {
    return result[0];
  }
}

void solve()
{
  int res = three(N, 0, 0);
  if (res != -2) {
    answer[res + 1]++;
  };
}

void print()
{
  FOR(i, 3) {
    cout << answer[i] << '\n';
  }
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