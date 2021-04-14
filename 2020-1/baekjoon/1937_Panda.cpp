#include <iostream>
#include <algorithm>

using namespace std;

int n;
int forest[502][502] = {0};
int DP[502][502] = {0};
int moving[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int eating(int i, int j, int prev_bamboo)
{
  if (i < 1 || j < 1 || i > n+1 || j > n+1) {
    return -1;
  }

  if (forest[i][j] <= prev_bamboo) {
    return 1;
  }

  if (DP[i][j] != 0) {
    return DP[i][j] + 1;
  }
  

  for (int m = 0; m < 4; m++) {
    DP[i][j] = max(DP[i][j], eating(i + moving[m][0], j + moving[m][1], forest[i][j]));
  }
  return DP[i][j] + 1;
}

void input()
{
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> forest[i][j];
    }
  }
}

void solve()
{
  int i, j;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      eating(i, j, -1);
    }
  }
}

void answer()
{
  int maximum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      maximum = max(maximum, DP[i][j]);
    }
  }
  cout << maximum;
}

int main()
{
  input();
  solve();
  answer();
}