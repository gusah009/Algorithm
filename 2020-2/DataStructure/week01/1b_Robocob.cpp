#include <iostream>
using namespace std;
#define FOR(n) for(int i = 0; i < n; i++)
int main() {
  int K;
  int xy[51][2];
  int answer_xy[2];
  int T;
  cin >> K;
  FOR(K) {
    cin >> xy[i][0] >> xy[i][1];
  }
  xy[K][0] = xy[0][0];
  xy[K][1] = xy[0][1];
  FOR(5) {
    cin >> T;
    FOR(2)
      answer_xy[i] = xy[0][i];
    int k = 0;
    while(true) {
      if (K == 1 || T == 0)
        break;
      if (xy[k][0] == xy[k+1][0]) {
        int dist = abs(xy[k][1] - xy[k+1][1]);
        if (dist > T) {
          if (xy[k+1][1] - xy[k][1] > 0) {
            answer_xy[1] = xy[k][1] + T;
          }
          else {
            answer_xy[1] = xy[k][1] - T;
          }
          T = 0;
        } else {
          T -= dist;
          answer_xy[1] = xy[k+1][1];
        }
        answer_xy[0] = xy[k][0];
      } else if (xy[k][1] == xy[k+1][1]) {
        int dist = abs(xy[k][0] - xy[k+1][0]);
        if (dist > T) {
          if (xy[k+1][0] - xy[k][0] > 0) {
            answer_xy[0] = xy[k][0] + T;
          }
          else {
            answer_xy[0] = xy[k][0] - T;
          }
          T = 0;
        } else {
          T -= dist;
          answer_xy[0] = xy[k+1][0];
        }
        answer_xy[1] = xy[k][1];
      }
      k++;
      k %= K;
    }
    cout << answer_xy[0] << " " << answer_xy[1] << "\n";
  }
}