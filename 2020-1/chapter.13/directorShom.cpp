#include <iostream>

using namespace std;

int N;
int number = 666;

bool solve()
{
  int tmp;
  for(tmp = number; tmp > 100; tmp/=10) {
    if(tmp%1000 == 666) {
      return false;
    }
  }
  return true;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    while(solve()) {
      number++;
    }
    number++;
  }
  cout << number - 1;
}