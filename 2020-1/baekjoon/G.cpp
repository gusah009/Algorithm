#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>         // greater 사용 위해 필요  
using namespace std;

int N;
int h[100001] = {0};
int water1[100001] = {0};
int water2[100001] = {0};
int total1 = 0, total2 = 0;
bool state = true;

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> h[n];
  }
  sort(&h[0], &h[N], greater<int>());
}

void solve()
{
  for (int n = 0; n < N - 1; n++) {
    if (h[n]%3 == 1) {
      h[n + 1] -= 2;
    }
    else if (h[n]%3 == 2) {
      h[n + 1] -= 1;
    }
    if (h[n + 1] < 0) {
      state = false;
      break;
    }
  }
  if(state) {
    if (h[N-1] % 3 == 0) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  else {
    cout << "NO\n";
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