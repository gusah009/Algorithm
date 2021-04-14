#include<iostream>
using namespace std;
#define FOR(i,j) for(int i = 0; i < j; i++)
int main() {
  int K,T,d, xy[51][6] = {0};
  double c[2][4] = {0};
  cin >> K ;
  FOR(k,K)
    cin >> xy[k][0] >> xy[k][1];
  FOR(i,2)
    xy[K][i] = xy[0][i];
  cin >> c[0][0] >> c[0][1] >> c[1][0] >> c[1][1] >> T;
  FOR(k,K) {
    FOR(i,2)
      if (xy[k][i] == xy[k+1][i]) {
        xy[k][3-i] = (xy[k+1][!i] - xy[k][!i]);
        xy[k+1][5-i] = -(xy[k+1][!i] - xy[k][!i]);
        FOR(j,2)
          if (c[j][i] == xy[k][i])
            if (min(xy[k][!i],xy[k+1][!i]) < c[j][!i] && c[j][!i] < max(xy[k][!i],xy[k+1][!i])) {
              i == 1 ? c[j][2] = j-0.5 : c[j][3] = j-0.5;
            }
      }
  }
  FOR(t,T) {
    FOR(i,2) {
      if (c[0][0] == c[1][0] && c[0][1] == c[1][1]) {
        FOR(j,2)
          c[j][2] != 0 ? c[j][2] = -c[j][2] : c[j][3] = -c[j][3];
        d = !d;
      } else
        FOR(k,K) {
          FOR(j,2)
            if (c[j][0] == xy[k][0] && c[j][1] == xy[k][1]) {
              FOR(a,2) c[j][2+a] = 0;
              if (d == j) xy[k][2] != 0 ? c[j][2] = xy[k][2] : c[j][3] = xy[k][3];
              else xy[k][4] != 0 ? c[j][2] = xy[k][4] : c[j][3] = xy[k][5];
            }
        }
        
      cout << i << " " << " " << c[i][2] << " : " << c[i][3] << "\n";
      FOR(j,2)
        FOR(a,2)
          if (c[j][2+a] != 0)
            c[j][2+a] > 0 ? c[j][a]+=0.5 : c[j][a]-=0.5;
      FOR(i,2)
        cout << c[i][0] << " " << c[i][1] << "\n";
    }
    cout << "\n";
  }
  FOR(i,2)
    cout << c[i][0] << " " << c[i][1] << "\n";

}