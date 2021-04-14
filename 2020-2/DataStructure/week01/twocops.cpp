#include <iostream>
using namespace std;

#define FOR(i,j) for(int i = 0; i < j; i++)
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int K, T;
int x[51], y[51];
int dir[51][2];  //[0] : 시계방향 , [1] : 반시계방향
double c1[2], c2[2]; // [0,1] : x,y
int c1_d, c2_d; // robocop의 방향
bool d = 0; // [0] : (1은 +, 2는 -), [1] : (1은 -, 2는 +)

int main()
{
  cin >> K;
  FOR(k,K) {
    cin >> x[k] >> y[k];
    if (k == 0) {
      c1[0] = x[k];
    } else if (k == K/2) {

    }
  }
  x[K] = x[0];
  y[K] = y[0];
  c1[0] = x[0];
  c1[1] = y[0];
  c2[0] = x[K/2-1];
  c2[1] = y[K/2-1];
  cin >> T;

  FOR(k,K) { // 시계방향으로 순회하면서 점마다 시계/반시계 방향 저장
    if (x[k] == x[k+1]) {
      if (y[k+1] > y[k]) {
        dir[k][0] = UP;
        dir[k+1][1] = DOWN;
        
      } else {
        dir[k][0] = DOWN;
        dir[k+1][1] = UP;
      }
    } else {
      if (x[k+1] > x[k]) {
        dir[k][0] = RIGHT;
        dir[k+1][1] = LEFT;
      } else {
        dir[k][0] = LEFT;
        dir[k+1][1] = RIGHT;
      } 
    }
    // 초기 로봇 이동 방향 설정
    if (c1[0] == x[k] || c1[1] == y[k])
      if (min(y[k], y[k+1]) <= c1[1] && c1[1] < max(y[k],y[k+1]) || min(x[k], x[k+1]) <= c1[0] && c1[0] < max(x[k],x[k+1]))
        c1_d = dir[k][0];
    if (c2[0] == x[k] || c2[1] == y[k])
      if (min(y[k], y[k+1]) < c2[1] && c2[1] <= max(y[k],y[k+1]) || min(x[k], x[k+1]) < c2[0] && c2[0] <= max(x[k],x[k+1]))
        c2_d = dir[k+1][1];
  }
  dir[0][1] = dir[K][1];

  FOR(t,T) {
    FOR(i,2) { // 0.5씩 2번
      if (c1[0] == c2[0] && c1[1] == c2[1]) { // 충돌하면
        c1_d = (c1_d/2)*2 + !(c1_d%2); // 방향 반대로 전환
        c2_d = (c2_d/2)*2 + !(c2_d%2); // 방향 반대로 전환
        d = !d;
      } else { // 점을 지나가면
        FOR(k,K) {
          if (c1[0] == x[k] && c1[1] == y[k]) {
            if (d) // 역방향
              c1_d = dir[k][1];
            else // 정방향
              c1_d = dir[k][0];
          }
          if (c2[0] == x[k] && c2[1] == y[k]) {
            if (d) // 역방향
              c2_d = dir[k][0];
            else // 정방향
              c2_d = dir[k][1];
          }
        }
      }
      switch (c1_d) { // 로봇 이동
        case UP:
          c1[1] += 0.5;
          break;
        case DOWN:
          c1[1] -= 0.5;
          break;
        case LEFT:
          c1[0] -= 0.5;
          break;
        case RIGHT:
          c1[0] += 0.5;
          break;
      }
      switch (c2_d) { // 로봇 이동
        case UP:
          c2[1] += 0.5;
          break;
        case DOWN:
          c2[1] -= 0.5;
          break;
        case LEFT:
          c2[0] -= 0.5;
          break;
        case RIGHT:
          c2[0] += 0.5;
          break;
      }
    }
  }
  cout << c1[0] << " " << c1[1] << "\n";
  cout << c2[0] << " " << c2[1] << "\n";
}