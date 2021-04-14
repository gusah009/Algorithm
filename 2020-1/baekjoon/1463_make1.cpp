#include <iostream>

#define INF 1234567890
using namespace std;

int n;
int count = 4;
int DP[1000001];

void input()
{
  cin >> n;
  DP[1] = 0;
  DP[2] = 1;
  DP[3] = 1;
}

void solve()
{
  while (count < n + 1) {
    DP[count] = INF;
    if (count%3 == 0) {
      DP[count] = min(DP[count], DP[count/3] + 1);
    }
    if (count%2 == 0) {
      DP[count] = min(DP[count], DP[count/2] + 1);
    }
    DP[count] = min(DP[count], DP[count-1] + 1);
    count++;
  }
}

void answer()
{
  cout << DP[n] << endl;
}

int main()
{
  input();
  solve();
  answer();
}