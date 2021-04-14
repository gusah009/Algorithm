#include <iostream>
#include <vector>
using namespace std;
// 결국 못품

int N, K;
int answer = 0;
int plugged[101];
int schedule[101];
bool state = false;

void input()
{
  cin >> N >> K;
  for (int k = 0; k < K; k++) {
    cin >> schedule[k];
  }
}

void solve()
{
  for (int i = 0; i < K; i++) {
    state = false;
    for (int j = 0; j < N; j++) {
      if (plugged[j] == schedule[i]) {
        state = true;
        break;
      }
    }

    if(state) {
      continue;
    }

    for (int j = 0; j < N; j++) {
      if (plugged[j] == 0) {
        plugged[j] = schedule[i];
        state = true;
        break;
      }
    }

    if(state) {
      continue;
    }

    int curridx = -1;
    int idx = 0;
    for (int j = 0; j < N; j++) { // plug 확인
      int lastidx = 0;
      for (int k = i + 1; k < K; k++) { // 이후 schedule 확인
        if (plugged[j] == schedule[k]) {
          break;
        }
        lastidx++;
      }
      if (lastidx > curridx) {
        idx = j;
        curridx = lastidx;
      }
    }

    plugged[idx] = schedule[i];
    answer++;
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