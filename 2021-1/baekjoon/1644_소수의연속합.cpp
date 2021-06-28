#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N;
int prime[1000001] = {0};
int arr[4000001];
int length = 0;
int answer = 0;

void input()
{
  cin >> N;
}

void getChe()
{
  int i = 2;
  // 입력받은 수 만큼 배열에 모두 초기화 해둔다
  for (i = 2; i <= N; i++)
  {
    arr[i] = i;
  }
  for (i = 2; i <= N; i++)
  {
    if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
      continue;
    for (int j = i + i; j <= N; j += i)
    { // i를 제외한 i의 배수들은 0으로 체크
      arr[j] = 0;
    }
  }
  // print
  for (i = 2; i <= N; i++)
  {
    if (arr[i] != 0) {
      // cout << arr[i] << " ";
      prime[length++] = arr[i];
    }
  }
  // cout << length << '\n';
}

void solve()
{
  getChe();
  
  int i = 0, j = 0;
  int sum = 0;
  while(j != length + 1) {
    while(i < j && sum >= N) {
      // cout << i << ' ' << j << '\n';
      if (sum == N) {
        // cout << i << ':' << j << '\n';
        answer++;
      }
      sum -= prime[i];
      i++;
    }
    sum += prime[j];
    j++;
  }
  while(i < j && sum >= N) {
    // cout << i << ' ' << j << '\n';
    if (sum == N) {
        // cout << i << ' ' << j << '\n';
        answer++;
    }
    sum -= prime[i];
    i++;
  }
}

void print()
{
  cout << answer << '\n';
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}