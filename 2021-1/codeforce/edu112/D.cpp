#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, M, l, r, answer;
int complex[6][200001] = {0};
string inp, new_inp;

void input_solve_print()
{
  cin >> N >> M;
  cin >> inp;

  string a[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};

  FOR(i, 6) {
    complex[i][0] = 0;
    for (int n = 0; n < N; n++) {
      if (a[i][n % 3] != inp[n]) {
        complex[i][n + 1] = complex[i][n] + 1;
      } else {
        complex[i][n + 1] = complex[i][n];
      }
    }
    // complex[i][N] = complex[i][N - 1];
  }

  FOR(m, M) {
    cin >> l >> r;

    answer = INF;
    FOR(i, 6) {
      answer = min(answer, complex[i][r] - complex[i][l - 1]);
    }

    cout << answer << '\n';
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve_print();
}