#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

string name;
int makePalin[26] = {0};
string answer = "";

void input()
{
  cin >> name;
}

void solve()
{
  FOR(n, name.size()) {
    makePalin[name[n] - 'A']++;
  }
  
  bool isOdd = false;
  int odd = 0;
  FOR(i, 26) {
    if (makePalin[i] % 2 == 1) {
      if (!isOdd) {
        isOdd = true;
        odd = i;
      } else {
        answer = "I\'m Sorry Hansoo";
        return;
      }
    }
  }
  if (!isOdd) {
    FOR(i, 26) {
      FOR(j, makePalin[i] / 2) {
        answer += (i + 'A');
      }
    }
    for(int i = 25; i >= 0; i--) {
      FOR(j, makePalin[i] / 2) {
        answer += (i + 'A');
      }
    }
  } else {
    FOR(i, 26) {
      FOR(j, makePalin[i] / 2) {
        answer += (i + 'A');
      }
    }
    answer += (odd + 'A');
    for(int i = 25; i >= 0; i--) {
      FOR(j, makePalin[i] / 2) {
        answer += (i + 'A');
      }
    }
  }
}

void print()
{
  cout << answer;
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