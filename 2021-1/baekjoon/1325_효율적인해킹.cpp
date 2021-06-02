#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
bool isExist[10001] = {0};
vector<int> computer[10001];
pair<int, int> answer[10001];
int MAX_NUM = -1;

void input()
{
  cin >> N >> M;
  FOR(m, M) {
    int A, B;
    cin >> A >> B;
    computer[B].push_back(A);
  }

  FOR(i, 10001) {
    answer[i].first = 0;
    answer[i].second = 0;
  }
}

int check(int n)
{
  if (isExist[n]) {
    return 0;
  }

  isExist[n] = true;
  if (computer[n].size() == 0) {
    return 1;
  }

  int result = 1;
  FOR(i, computer[n].size()) {
    result += check(computer[n][i]);
  }
  return result;
}

void solve()
{
  for (int n = 1; n < N + 1; n++) {
    fill(&isExist[0], &isExist[N + 1], false);
    answer[n].first = check(n);
    answer[n].second = n;
    MAX_NUM = MAX_NUM > answer[n].first ? MAX_NUM : answer[n].first;
  }
}

void print()
{
  vector<int> ans;
  FOR(n, N + 1) {
    if (answer[n].first == MAX_NUM) {
      ans.push_back(answer[n].second);
    }
  }
  sort(ans.begin(), ans.end());
  FOR(i, ans.size()) {
    cout << ans[i] << ' ';
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