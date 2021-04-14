#include <iostream>
#include <vector>

using namespace std;

int N;
int grade[51] = {0};
vector<int> x, y;
vector<int> ranking;

void input()
{
  cin >> N;
  int tmp_x, tmp_y;
  for(int i = 0; i < N; i++) {
    cin >> tmp_x >> tmp_y;
    x.push_back(tmp_x);
    y.push_back(tmp_y);
    ranking.push_back(1);
  }
}

void solve()
{
  for(int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(i != j) {
        if(x[i] < x[j] && y[i] < y[j]) {
          ranking[i]++;
        }
      }
    }
  }

  for(int i = 0; i < N; i++) {
    cout << ranking[i] << " ";
  }
}

int main()
{
  input();
  solve();
}