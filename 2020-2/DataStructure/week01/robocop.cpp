#include <iostream>
using namespace std;
int main()
{
  int K,T,i,answer_x, answer_y, x[51], y[51];
  cin >> K;
  for (int k = 0; k < K; k++) {
    cin >> x[k] >> y[k];
  }
  x[K] = x[0];
  y[K] = y[0];
  for (int t = 0; t < 5; t++) {
    cin >> T;
    answer_x = x[0];
    answer_y = y[0];
    int k = 0;
    while(true) {
      if (K == 1 || T == 0)
        break;
      if (x[k] == x[k+1]) {
        int dist = abs(y[k] - y[k+1]);
        if (dist > T) {
          if (y[k+1] - y[k] > 0) {
            answer_y = y[k] + T;
          }
          else {
            answer_y = y[k] - T;
          }
          T = 0;
        } else {
          T -= dist;
          answer_y = y[k+1];
        }
      } else{
        int dist = abs(x[k] - x[k+1]);
        if (dist > T) {
          if (x[k+1] - x[k] > 0) {
            answer_x = x[k] + T;
          }
          else {
            answer_x = x[k] - T;
          }
          T = 0;
        } else {
          T -= dist;
          answer_x = x[k+1];
        }
      }
      k++;
      k %= K;
    }
    std::cout << answer_x << " " << answer_y << "\n";
  }
}