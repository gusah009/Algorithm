#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N;
int d[8], r[8], rd[8], ld[8];
int board[8][8] = {0};

void input()
{

  ifstream in("marathon.inp");
  in >> N;
  FOR(n, N)
  {
    in >> d[n];
  }
  FOR(n, N)
  {
    in >> r[n];
  }
  FOR(n, N * 2 - 1)
  {
    in >> rd[n];
  }
  FOR(n, N * 2 - 1)
  {
    in >> ld[n];
  }
  in.close();
}

void backtracking(int n, int d)
{
  switch (d)
  {
  case 0:
    FOR(i, n)
    {
      board[]
    }
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  }
}

void solve()
{
  FOR(n, N)
  {
    FOR(d, 4)
    {
      backtracking(n + 1, d);
    }
  }
}

void print()
{
  ofstream out("marathon.out");
  out << "None\n";
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