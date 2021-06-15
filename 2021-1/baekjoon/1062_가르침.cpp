#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, K;
bool isExist[26] = {0};
bool words[50][26] = {0};

void input()
{
  cin >> N >> K;
  FOR(n, N) {
    string word;
    cin >> word;
    FOR(i, word.size()) {
      words[n][word[i] - 'a'] = true;
      isExist[word[i] - 'a'] = true;
    }
  }
}

void solve()
{
  FOR(n, N) {
  }

}

void print()
{

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