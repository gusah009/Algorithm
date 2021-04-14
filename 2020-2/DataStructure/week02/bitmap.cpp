#include <iostream>
#include <bitset>

#define ll long long int
#define SIZE 64
#define FOR(i) for (int i = 0; i < SIZE; i++)
using namespace std;

int main()
{
  ll bmap[SIZE];
  ll tmap[SIZE];
  ll tmp;
  bitset<SIZE> bit;

  FOR(i) {
    cin >> bmap[i];
  }
  FOR(i) {
    FOR(j) {
      bitset<SIZE> b;
      b = bmap[j];
      bit[SIZE-1-j] = b[SIZE-1-i];
    }
    tmap[i] = (ll)bit.to_ullong();
  }
  FOR(i) {
    cout << tmap[i] << "\n";
  }
}