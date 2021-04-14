#include <iostream>

using namespace std;

int N;

void input()
{
  cin >> N;
}

void solve()
{
  int divide = 0;
  int sum = 0;
  int answer = 0;
  for (int i = 0; i < N; i++) {
    divide = i;
    sum = i;
    while(divide%10 != 0) {
      sum += divide%10;
      divide/=10;
    }
    if(N == sum) {
      answer = i;
      break;
    }
  }
  cout << answer;
}

int main()
{
  input();
  solve();
}