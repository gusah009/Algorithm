#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double px[3], py[3];
double PI = 3.14159;
double seta;
int answer;

void input()
{
  for (int i = 0; i < 3; i++) {
    cin >> px[i] >> py[i];
  }
}

void solve()
{
  int tmp = px[0]*py[1]+px[1]*py[2]+px[2]*py[0];
    tmp = tmp - py[0]*px[1]-py[1]*px[2]-py[2]*px[0];
    if (tmp > 0) {
        cout << 1;
    } else if (tmp < 0) {
        cout << -1;
    } else {
        cout << 0;
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