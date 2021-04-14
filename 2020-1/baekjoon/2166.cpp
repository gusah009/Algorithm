#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int N;
double result = 0;
double xy[10000][2];

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> xy[n][0] >> xy[n][1];
  }
}

void solve()
{
  for (int n = 0; n < N - 1; n++) {
    result += (xy[n][0]*xy[n+1][1] - xy[n+1][0]*xy[n][1]);
  }
  result += (xy[N - 1][0]*xy[0][1] - xy[0][0]*xy[N - 1][1]);
  result = abs(result);
  result /= 2;
}

void print()
{ 
  cout << fixed;
  cout.precision(1);
  cout << result;
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