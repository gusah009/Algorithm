#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;

int N, A, B;
vector< tuple<int, int, int, int> > team;
unsigned long long int answer = 0;
bool is_end = false;

void input()
{
  int tmp[4];
  cin >> N >> A >> B;
  if (N == 0 && A == 0 && B == 0) { // 0 0 0
    is_end = true;
    return;
  }
  for (int n = 0; n < N; n++) {
    cin >> tmp[1] >> tmp[2] >> tmp[3];
    tmp[0] = abs(tmp[2] - tmp[3]);
    team.push_back(make_tuple(tmp[0], tmp[1], tmp[2], tmp[3]));
    // 0:차이, 1:풍선 수, 2:A거리, 3:B거리
  }
  sort(team.rbegin(), team.rend());
}

void solve()
{
  for (int n = 0; n < N; n++) {
    if (get<2>(team[n]) > get<3>(team[n])) { // A거리 > B거리
      if (get<1>(team[n]) > B) { // 필요한 풍선이 남은 풍선보다 많으면
        answer += B * get<3>(team[n]);
        answer += (get<1>(team[n]) - B) * get<2>(team[n]);
        A -= (get<1>(team[n]) - B);
        B -= B;
      }
      else {
        answer += get<1>(team[n]) * get<3>(team[n]);
        B -= get<1>(team[n]);
      }
    }
    else {
      if (get<1>(team[n]) > A) { // 필요한 풍선이 남은 풍선보다 많으면
        answer += A * get<2>(team[n]);
        answer += (get<1>(team[n]) - A) * get<3>(team[n]);
        B -= (get<1>(team[n]) - A);
        A -= A;
      }
      else {
        answer += get<1>(team[n]) * get<2>(team[n]);
        A -= get<1>(team[n]);
      }
    }
  }
  // for (int n = 0; n < N; n++) {
  //   cout << get<0>(team[n]) << get<1>(team[n]) << get<2>(team[n]) << get<3>(team[n]) << "\n";
  // }
}

void print()
{
  cout << answer << "\n";
  answer = 0;
  team.clear();
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(true) {
    input();
    if (is_end) {
      break;
    }
    solve();
    print();
  }
}