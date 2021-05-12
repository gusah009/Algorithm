#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

string str;
string boom;
vector<char> answer;

void input()
{
  cin >> str;
  cin >> boom;
}

void solve()
{

  FOR(i, str.size()) {
    bool boomFlag = false;
    if (str[i] == boom[0]) {
      boomFlag = true;
      for(int j = 1; j < boom.size(); j++) {
        if (str[i + j] != boom[j]) {
          boomFlag = false;
          break;
        }
      }
    }
    if (boomFlag) {
      i--;
      FOR(j, boom.size()) {
        if (!answer.empty()) {
          str[i + (boom.size() - j)] = answer.back();
          answer.pop_back();
        } else {
          i += boom.size() - j;
          break;
        }
      }
    } else {
      answer.push_back(str[i]);
    }
  }
}

void print()
{
  if (answer.size() == 0) {
    cout << "FRULA";
  } else {
    FOR(i, answer.size()) {
      cout << answer[i];
    }
  }
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