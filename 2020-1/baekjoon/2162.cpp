#include <iostream>
#include <vector>
using namespace std;

int N;
int xy1[3000][2], xy2[3000][2];
int group[3000][2] = {0}; // 0 : 그룹번호, 1 : 그룹에속한 점 개수
int gr[3000] = {0};
int maximum[2] = {0};
int g = 0;

int area(int* a, int* b, int* c) 
{
  return (a[0] * b[1] - a[1] * b[0] + b[0] * c[1] - b[1] * c[0] + c[0] * a[1] - c[1] * a[0]) / 2;
}

bool is_divide(int* _xy1, int* _xy2, int * _xy3, int* _xy4)
{
  if (area(_xy1, _xy2, _xy3) * area(_xy1, _xy2, _xy4) <= 0) {
    cout << "yes!\n";
  }
  if (area(_xy3, _xy4, _xy1) * area(_xy3, _xy4, _xy2) <= 0) {
    cout << "yes2!\n";
  }
  bool answer = (area(_xy1, _xy2, _xy3) * area(_xy1, _xy2, _xy4) <= 0) && (area(_xy3, _xy4, _xy1) * area(_xy3, _xy4, _xy2) <= 0);
  return (answer);
}

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    group[n][0] = n;
    group[n][1] = 1;
  }
  for (int n = 0; n < N; n++) {
    cin >> xy1[n][0] >> xy1[n][1] >> xy2[n][0] >> xy2[n][1];
  }
}

void solve()
{
  for (int n = 1; n < N; n++) {
    for (int i = 0; i < n; i++) {
      cout << n << " " << i << "\n";
      if (is_divide(xy1[n], xy2[n], xy1[i], xy2[i])) { // 이 선분들이 만난다면        
        group[i][0] = group[i][0] < group[n][0] ? group[i][0] : group[n][0];
        group[n][0] = group[i][0] < group[n][0] ? group[i][0] : group[n][0];
        // cout << n << " " << i << "meet!\n";
      }
      else { // 이 선분들이 안만난다면
      }
    }
  }

  for (int n = 0; n < N; n++) {
    gr[group[n][0]]++;
  }

  for (int n = 0; n < N; n++) {
    if (gr[n] != 0) {
      maximum[0]++;
    }
    if (maximum[1] < gr[n]) {
      maximum[1] = gr[n];
    }
  }
}

void print()
{
  cout << maximum[0] << "\n" << maximum[1];
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