#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int N;
int T[100000];
vector< int > p, q;
int total = 0;

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> T[n];
  }
  sort(&T[0], &T[N], greater<int>());
  int p_total = 0, q_total = 0;
  for (int n = 0; n < N; n++) {
    if (p_total > q_total) {
      q.push_back(T[n]);
      q_total += T[n];
    }
    else {
      p.push_back(T[n]);
      p_total += T[n];
    }
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  p_total = 0, q_total = 0;
  for (int i = 0; i < p.size(); i++) {
    p_total += p[i];
    p[i] = p_total;
  }
  for (int i = 0; i < q.size(); i++) {
    q_total += q[i];
    q[i] = q_total;
  }
} 

void solve()
{
  int cp = 0, cq = 0;
  for (int n = 0; n < N; n++) {
    if (cq == q.size()) {
      T[n] = p[cp];
      cp++;
    }
    else if (cp == p.size()){
      T[n] = q[cq];
      cq++;
    }
    else if (p[cp] < q[cq]) {
      T[n] = p[cp];
      cp++;
    }
    else {
      T[n] = q[cq];
      cq++;
    }
  }
  for (int n = 1; n < N; n++) {
    total += T[n] - T[n-1];
  }
}

void print()
{
  if (total%(N-1) == 0) {
    cout << total/(N-1) << "\n";
  }
  else {
    cout << total/(N-1) + 1 << "\n";
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