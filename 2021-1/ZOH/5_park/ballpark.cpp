#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int board[1001][1001];

void input()
{
  FOR(i, 1001) {
    FOR (j, 1001) {
      board[i][j] = -1;
    }
  }

  ifstream in("ballpark.inp");

  in >> N >> M;
  char tmp;
  in.get(tmp);
  // cout << N << M;
  FOR(n, N) {
    char a[1024];
    in.getline(a, 1024);    //한줄씩 읽어오기
    FOR(m, M) {
      if (a[m] == '0') {
        board[N - n - 1][m] = 0;
      }
    }
  }
}

int initBoard(int n, int m) {
  if (board[n][m] == -1) return 0;
  if (board[n][m] !=  0) return board[n][m];
  int a = initBoard(n + 1, m);
  int b = initBoard(n, m + 1);
  int c = initBoard(n + 1, m + 1);
  board[n][m] = 1 + min(min(a, b), c);
  return board[n][m];
}

void solve()
{
  // FOR(n, N) {
  //   FOR(m, M) {
  //     cout << board[n][m] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "=-=-=-=-=-=-=-=-=-=-==-=-==--=\n";
  FOR(n, N) {
    FOR(m, M) {
      if (board[n][m] == 0) {
        initBoard(n, m);
      }
    }
  }
  // FOR(n, N) {
  //   FOR(m, M) {
  //     cout << board[n][m] << " ";
  //   }
  //   cout << "\n";
  // }
}

void print()
{
  string output = "";

  int maxSize = 0;
  FOR(n, N) {
    FOR(m, M) {
      maxSize = max(maxSize, board[n][m]);
    }
  }

  int r = 0;
  FOR(m, M) {
    FOR(n, N) {
      if (board[n][m] == maxSize) {
        r++;
        output += to_string(m + 1) + " " + to_string(n + 1) + "\n";
      }
    }
  }
  output.insert(0, to_string(maxSize) + " " + to_string(r) + "\n");
  ofstream out("ballpark.out");
  out<< output << endl;
  out.close();
}

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  input();
  solve();
  print();
}