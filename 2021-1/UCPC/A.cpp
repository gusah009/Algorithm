#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

string S;
int A, B;

void input()
{
  cin >> S;
}

void solve()
{
  int len = 1;
  while (true) {
    bool flag = true;
    int i = stoi(S.substr(0, len++));
    A = i;
    for(int s = len - 1; s < S.size();) {
      i++;
      string new_i = to_string(i);
      bool flag2 = true;
      FOR(j, new_i.size()) {
        if (new_i[j] != S[s]) {
          flag2 = false;
          break;
        }
        s++;
      }
      if (!flag2) {
        flag = false;
        break;
      }
    }
    if (flag) {
      B = i;
      break;
    }
  }
}

void print()
{
  cout << A << ' ' << B;
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