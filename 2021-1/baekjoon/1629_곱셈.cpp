#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

unsigned long long A, B, C, answer = 1;
unsigned long long counting = 0;
void input()
{
  cin >> A >> B >> C;
}

unsigned long long multiple(unsigned long long multy)
{
  // counting++;
  if (multy == 1) {
    return A;
  } else if (multy == 0) {
    return 0;
  }
  unsigned long long result = multiple(multy / 2);
  return result * result % C;
}

void solve()
{
  while (B != 0) {
    unsigned long long i = 1;
    while(i <= B) {
      i *= 2;
    }
    answer *= multiple(i / 2);
    answer %= C;
    B -= i / 2;
    // cout << "B: " <<  B << '?' << i << '\n';
  }
}

void print()
{
  // cout << counting << '\n';
  cout << answer % C << '\n';
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