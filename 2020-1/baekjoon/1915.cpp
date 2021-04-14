#include <iostream>
#include <vector>
using namespace std;

int N, M;
int answer = 0;
int n_move[3][2] = {
  {-1 ,0},
  {0, -1},
  {-1, -1}
};
int nm[1000][1000];

void input()
{
  cin >> N >> M;
  for (int n = 0; n < N; n++) {
    string tmp;
    cin >> tmp;
    for (int m = 0; m < M; m++) {
      nm[n][m] = tmp[m] - '0';
    }
  }

  for (int n = 0; n < N; n++) {
    if (nm[n][0] == 1) {
      answer = 1;
    }
  }

  for (int m = 0; m < M; m++) {
    if (nm[0][m] == 1) {
      answer = 1;
    }
  }
}

void solve()
{
  for (int n = 1; n < N; n++) {
    for (int m = 1; m < M; m++) {
      if (nm[n][m] == 1) {
        int tmp = nm[n + n_move[0][0]][m + n_move[0][1]];
        int i;
        for (i = 1; i < 3; i++) {
          tmp = min(tmp, nm[n + n_move[i][0]][m + n_move[i][1]]);
          if(tmp == 0) {
            break;
          }
        }
        if (i == 3) {
          nm[n][m] = tmp + 1;
        }
      }
    }
  }
}

void print()
{
  int n_max = 0;
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      n_max = max(n_max, nm[n][m]);
    }
  }
  cout << n_max * n_max;
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