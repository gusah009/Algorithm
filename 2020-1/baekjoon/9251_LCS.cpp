#include <iostream>

using namespace std;

int DP[1001][1001] = {0};

string s1, s2;

void input()
{
  cin >> s1 >> s2;
}

void solve()
{
  for (int i = 1; i <= s2.length(); i++) {
    for (int j = 1; j <= s1.length(); j++) {
      if(s2[i - 1] == s1[j - 1]) {
        DP[i][j] = DP[i - 1][j - 1] + 1;
      }
      else {
        DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
      }
    }
  }
  cout << DP[s2.length()][s1.length()];
}

int main()
{
  input();
  solve();
}