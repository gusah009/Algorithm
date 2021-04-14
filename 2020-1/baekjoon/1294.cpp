#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int total_len = 0;
pair<string, string> str[20];
string answer = "";

void input()
{
  int max_len = 0;
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> str[n].second;
    str[n].first = str[n].second;
    total_len += str[n].second.length();
    max_len = max(max_len, (int)str[n].second.length());
  }
  for (int n = 0; n < N; n++) {
    while(str[n].first.length() != max_len) {
      str[n].first += 'Z';
    }
  }
}

void solve()
{
  while (total_len != 0) {
    char ans = 'Z' + 1;
    int idx = -1;
    sort(&str[0], &str[N]);
    for (int n = 0; n < N; n++) {
      if (str[n].second.length() != 0) {
        if (ans > str[n].first[0]) {
          ans = str[n].first[0];
          idx = n;
          break;
        }
      }
    }
    answer += ans;
    str[idx].first = str[idx].first.substr(1);
    str[idx].first += 'Z';
    str[idx].second = str[idx].second.substr(1);
    total_len--;
  }
}

void print()
{
  cout << answer << "\n";
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