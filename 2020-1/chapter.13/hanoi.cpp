#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int other)
{
  if(n == 1) {
    cout << from << " " << to << "\n";
    return;
  }
  hanoi(n-1, from, other, to);
  cout << from << " " << to << "\n";
  hanoi(n-1, other, to, from);
  return;
}

int main()
{
  int n;
  int K = 1;
  cin >> n;
  for(int i = 0; i < n; i++) {
    K *= 2;
  }
  cout << K-1 << "\n";
  hanoi(n, 1, 3, 2);
}


// n개 원반중 n-1개를 2번 기둥으로 옮긴다
// 1번 기둥에 남아 있는 가장 큰 원반을 3번 기둥으로 옮긴다
// 2번기둥에 있는 n-1개 원반을 다시 3번 기둥으로 옮긴다