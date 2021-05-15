#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N;
int d[8], r[8], rd[16], ld[16];
char board[8][8], checkBoard[8][8];
int cnt = 0;
bool ansFlag = false;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void input()
{
  ifstream in("ct.inp");
  in >> N;
  FOR(n, N)
  {
    in >> d[n];
    cnt += d[n];
    // cout << d[n] << ' ';
  }
  // cout << '\n';
  FOR(n, N)
  {
    in >> r[n];
    // cout << r[n] << ' ';
  }
  // cout << '\n';
  FOR(n, N * 2 - 1)
  {
    in >> rd[n];
    // cout << rd[n] << ' ';
  }
  // cout << '\n';
  FOR(n, N * 2 - 1)
  {
    in >> ld[n];
    // cout << ld[n] << ' ';
  }
  // cout << '\n';
  in.close();

  FOR(i, 8) {
    FOR(j, 8) {
      board[i][j] = '-';
    }
  }
}

int dfsCheck(int i, int j)
{
  // if (c == cnt) {
  //   ansFlag = true;
  //   return 0;
  // }
  
  if (checkBoard[i][j] != 'B' || board[i][j] != 'B') {
    return 0;
  }

  // cout << i << j << '\n';
  checkBoard[i][j] = '-';

  int res = 1;
  FOR(d, 4) {
    int next_i = i + dir[d][0];
    int next_j = j + dir[d][1];
    if (0 <= next_i && next_i < N && \
        0 <= next_j && next_j < N && !ansFlag) {
        res += dfsCheck(next_i, next_j);
      }
  }
  return res;
}
void backtracking(int i)
{
  // cout << '\n';
  if (i == N) {
    FOR(i, N) {
      FOR(j, N) {
        checkBoard[i][j] = board[i][j];
      }
    }
    FOR(i, N) {
      FOR(j, N) {
        if (checkBoard[i][j] == 'B') {
          if (cnt == dfsCheck(i, j)) {
            ansFlag = true;
          }
          return;
        }
      }
    }
    return;
  }

  vector<int> v;
  FOR(j, N) {
    if (j < r[i]) v.push_back(1);
    else v.push_back(0); 
  }
  do {
    bool flag = true;
    FOR(j, v.size()) {
      if (v[j]) {
        if (r[i] == 0 || d[j] == 0 || \ 
          rd[i + (N - j - 1)] == 0 || ld[i + j] == 0) {
            flag = false;
            break;
        }
      }
    }
    if (flag) {
      FOR(j, v.size()) {
        if (v[j]) {
          r[i]--;
          d[j]--;
          rd[i + (N - j - 1)]--;
          ld[i + j]--;
          board[i][j] = 'B';
        }
      }
      backtracking(i + 1);

      if (ansFlag) return;

      FOR(j, v.size()) {
        if (v[j]) {
          r[i]++;
          d[j]++;
          rd[i + (N - j - 1)]++;
          ld[i + j]++;
          board[i][j] = '-';
        }
      }
    }
  } while(prev_permutation(v.begin(), v.end()));
}

void solve()
{
  backtracking(0);
}

void print()
{
  FOR(i, N) {
    FOR(j, N) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  ofstream out("ct.out");
  FOR(i, N) {
    FOR(j, N) {
      out << board[i][j] << ' ';
    }
    out << '\n';
  }
  out.close();
}

  int main()
  {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    print();
  }