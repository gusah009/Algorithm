#include <iostream>

using namespace std;

int main() {
  unsigned long long int x, y;
  unsigned long long int a, b;
  unsigned long long int dollars[100];
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    cin >> x >> y >> a >> b;
    dollars[t] = 0;
    while(true) {
      if (x > 0 && y > 0) {
        if(x > y) {
          if (a * 2 > b) {
            dollars[t] += b*y;
            x -= y;
            y = 0;
          }
          else {
            dollars[t] += a*2*y;
            x -= y;
            y = 0;
          }
        }
        else {
          if (a * 2 > b) {
            dollars[t] += b*x;
            y -= x;
            x = 0;
          }
          else {
            dollars[t] += a*2*x;
            y -= x;
            x = 0;
          }
        }
      }
      else if (x == 0 && y == 0) {
        break;
      }
      else if (x == 0) {
        dollars[t] += a*y;
        y = 0;
      }
      else if (y == 0) {
        dollars[t] += a*x;
        x = 0;
      }
    }
  }

  for (int t = 0; t < T; t++) {
    cout << dollars[t] << "\n";
  }
}