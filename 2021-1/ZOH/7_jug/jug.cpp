/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int s[3], N[10];
char winner[101] = {0};
char DP_pass[4][101] = {0}, DP_nonpass[4][101] = {0}; //, DP_s[3][101] = {0}

void input()
{
  ifstream in("jug.inp");
  FOR(i, 3)
  {
    in >> s[i];
  }
  FOR(i, 10)
  {
    in >> N[i];
  }
  in.close();
}

void solve()
{
  FOR(i, s[0])
  {
    DP_pass[3][i] = 'S';
    DP_nonpass[3][i] = 'S';
    winner[i] = 'F';
  }
  for (int n = s[0]; n < 101; n++)
  {
    DP_nonpass[3][n] = 'S';
    bool flag_pass = false;
    FOR(i, 3)
    {
      if (n - s[i] >= 0)
      {
        bool flag = false;
        if (DP_pass[(i + 1) % 3][n - s[i]] == 0 && DP_pass[(i + 2) % 3][n - s[i]] == 0) {
          flag = true;
        } else {
          flag |= DP_pass[(i + 1) % 3][n - s[i]] == 'S';
          flag |= DP_pass[(i + 2) % 3][n - s[i]] == 'S';
        }
        DP_pass[i][n] = flag ? 'S' : 'F';
        flag_pass |= DP_pass[i][n] == 'S';
      }
    }
    DP_pass[3][n] = flag_pass ? 'F' : 'S';
    FOR(i, 3)
    {
      if (n - s[i] >= 0)
      {
        bool flag = false;
        flag |= DP_pass[3][n - s[i]] == 'S';
        flag |= DP_nonpass[(i + 1) % 3][n - s[i]] == 'S';
        flag |= DP_nonpass[(i + 2) % 3][n - s[i]] == 'S';
        DP_nonpass[i][n] = flag ? 'F' : 'S';
      }
    }
    bool flag = false;
    flag |= DP_pass[3][n] == 'S';
    flag |= DP_nonpass[0][n] == 'S';
    flag |= DP_nonpass[1][n] == 'S';
    flag |= DP_nonpass[2][n] == 'S';
    winner[n] = flag ? 'F' : 'S';
  }
}

void print()
{
  ofstream out("jug.out");
  FOR(n, 10)
  {
    out << winner[N[n]] << '\n';
  }
}

int main()
{
  input();
  solve();
  print();

  return 0;
}