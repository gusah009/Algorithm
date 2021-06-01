#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 1000000000

int N;
long long DP[101][10][1024] = {0};

void input()
{
  cin >> N;
}

void check(int i, int depth) {
  if (depth == N) {
    bool flag = true;
    FOR(j, 10) {
    }
    if (flag) {

    }
  }
}

void solve()
{
  FOR(i, 10) {
    DP[1][i][(1 << i)] = 1;
  }
  for(int n = 2; n <= N; n++) {
    FOR(i, 10) {
      FOR(j, 1024) {
        if (i > 0 && DP[n - 1][i - 1][j] != 0) {
          DP[n][i][(j | (1 << i))] += DP[n - 1][i - 1][j];
          DP[n][i][(j | (1 << i))] %= MAX;
        }
        if (i < 9 && DP[n - 1][i + 1][j] != 0) {
          DP[n][i][(j | (1 << i))] += DP[n - 1][i + 1][j];
          DP[n][i][(j | (1 << i))] %= MAX;
        }
      }
    }
  }
}
// 126461847755
// 1336256864572
void print()
{
  long long answer = 0;
  for(int i = 1; i < 10; i++) {
      answer += DP[N][i][1023];
      answer %= MAX;
  }
  cout << answer % MAX << '\n';
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