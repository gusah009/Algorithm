#include <iostream>

using namespace std;

bool num[2001] = {0};
int N;

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    num[tmp+1000] = true;
  }
  for(int i = 0; i < 2001; i++) {
    if(num[i]) {
      cout << i - 1000 << "\n";
    }
  }
}
