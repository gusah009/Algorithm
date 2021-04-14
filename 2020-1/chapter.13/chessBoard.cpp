#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;

int N, M;
int answer = INF;
vector< vector<char> > board;

void input()
{
  char tmp;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    vector<char> tmp_vec;
    for (int j = 0; j < M; j++) {
      cin >> tmp;
      tmp_vec.push_back(tmp);
    }
    board.push_back(tmp_vec);
  }
}

void solve()
{
  for (int i = 0; i <= N - 8; i++) {
    for (int j = 0; j <= M - 8; j++) {
      int count1 = 0;
      int count2 = 0;
      for (int a = 0; a < 0 + 8; a++) {
        for (int b = 0; b < 0 + 8; b++) {
          if (board[a + i][b + j] == 'B') {
            if((a+b)%2 == 0) {
              count1++;
            }
            else {
              count2++;
            }
          }
          else if (board[a + i][b + j] == 'W') {
            if((a+b)%2 == 1) {
              count1++;
            }
            else {
              count2++;
            }
          }
        }
      }
      answer = count1 < answer ? count1 : answer;
      answer = count2 < answer ? count2 : answer;
    }
  }
  cout << answer;
}

int main()
{
  input();
  solve();
}