#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
pair<int, int> ST[200001];
int INF = 1234567890;
bool state;
priority_queue <int,vector<int>,greater<int> > classroom;

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> ST[n].first >> ST[n].second;
  }
  sort(&ST[0], &ST[N]);
}

void solve()
{
  classroom.push(ST[0].second);
  for (int i = 1; i < N; i++) {
    if (classroom.top() > ST[i].first) { // 젤 작은거
      classroom.push(ST[i].second);
    }
    else {
      classroom.pop();
      classroom.push(ST[i].second);
    }
  }
}

void print()
{
  cout << classroom.size() << "\n";
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