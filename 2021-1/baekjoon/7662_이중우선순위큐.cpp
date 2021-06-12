#include <iostream>
#include <set>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, K;
multiset<int> Q;

void input_solve()
{
  cin >> K;
  FOR(k, K) {
    char oper;
    int n;
    cin >> oper >> n;
    if (oper == 'I') {
      // cout << "I!@#\n";
      Q.insert(n);
    } else if (oper == 'D') {
      if (!Q.empty()) {
          // cout << oper << n << "\n";
        if (n == 1) {
          auto it = Q.end();
          it--;
          Q.erase(it);
        } else if (n == -1) {
          Q.erase(Q.begin());
        }
      }
    }
  }
}

void print()
{
  if (Q.empty()) {
    cout << "EMPTY\n";
  } else {
    // cout << "#$!$#@";
    cout << *(Q.rbegin()) << ' ' << *(Q.begin()) << '\n';
  }
  Q.clear();
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  FOR(t, T) {
    input_solve();
    print();
  }
}