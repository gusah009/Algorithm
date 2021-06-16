#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
priority_queue<int> pq;

void input()
{
  cin >> N;
  FOR(n, N) {
    int num;
    cin >> num;
    if (num == 0) {
      if (pq.empty()) {
        cout << "0\n";
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(num);
    }
  }
}

void solve()
{
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