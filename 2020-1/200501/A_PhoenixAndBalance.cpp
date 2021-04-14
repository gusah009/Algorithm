#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int sum1 = 0, sum2 = 0;
    int N;
    cin >> N;
    for (int n = 1; n < N; n++) {
      if(n < N/2) {
        sum1 += pow(2,n);
      }
      else {
        sum2 += pow(2,n);
      }
    }
    sum1 += pow(2,N);
    cout << sum1 - sum2 << "\n";
  }
}