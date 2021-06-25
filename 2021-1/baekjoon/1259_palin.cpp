#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

string N;
bool answer;

void solve()
{
  int i = 0;
  while(i != N.size() / 2) {
    if (N[i] != N[N.size() - i - 1]) break;
    i++;
  }
  if (i == N.size() / 2) answer = true;
  else answer = false;
}

void print()
{
  answer ? cout << "yes\n" : cout << "no\n";
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(true) {
    cin >> N;
    if (N == "0") {
      return 0;
    }
    solve();
    print();
  }
}