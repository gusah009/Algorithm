#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, K;
pair<int, int> jam[300001];
multiset<int> C;
long long result = 0;

bool comp(const int& a, const int& b) {
	return a < b;
}

void input()
{
  cin >> N >> K;
  FOR(n, N) {
    int M, V;
    cin >> M >> V;
    jam[n] = make_pair(-V, M);
  }
  FOR(k, K) {
    int c;
    cin >> c;
    C.insert(c);
  }

  sort(&jam[0], &jam[N]);
}

void solve()
{
  FOR(n, N) {
    if (C.size() == 0) {
      break;
    }
    auto it = C.lower_bound(jam[n].second);
    if (it != C.end()) {
      result += -jam[n].first;
      C.erase(it);
    }
  }
}

void print()
{
  cout << result << '\n';
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