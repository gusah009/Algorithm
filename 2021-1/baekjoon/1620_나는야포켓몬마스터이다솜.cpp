#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
map<string, int> poketmon;
map<int, string> poketmon_num;

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    string tmp;
    cin >> tmp;
    poketmon.insert(make_pair(tmp, n + 1));
    poketmon_num.insert(make_pair(n + 1, tmp));
  }
}

void solve()
{
  FOR(m, M) {
    string tmp;
    cin >> tmp;
    if (isupper(tmp[0])) {
      cout << poketmon[tmp] << '\n';
    } else {
      cout << poketmon_num[stoi(tmp)] << '\n';
    }
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