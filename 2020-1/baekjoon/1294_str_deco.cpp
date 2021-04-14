#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string str[20];
string answer;

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> str[n];
  }
  sort(&str[0], &str[N]);
  answer = str[0];
}

void solve()
{
  int start_point = 0;
  int j_start_point;
  int j;
  for (int n = 1; n < N; n++) {
    bool state = true;
    // cout << answer << start_point << " " << j_start_point << "\n";
    for (j = start_point; j < answer.length(); j++) { // str의 첫번째 요소일 때
      if (state && answer[j] == str[n][0]) {
        state = false;
        j_start_point = j+1;
      }
      if (answer[j] > str[n][0]) {
        answer.insert(j, 1, str[n][0]);
        start_point = j+1;
        if(state) {
          j_start_point = j+1;
        }
        // cout << ";"+answer << " " << start_point << " " << j_start_point << "\n";
        break;
      }
      if (!state && answer[j] != str[n][0]) {
        state = true;
      }
    }
    if (j == answer.length()) {
      answer += str[n][0];
      if(state) {
        start_point = j;
        j_start_point = j+1;
      }
      // cout << ":"+answer << " " << start_point << " " << j_start_point << "\n";
    }

    for (int i = 1; i < str[n].length(); i++) {
      state = true;
      for (j = j_start_point; j < answer.length(); j++) {
        if (state && answer[j] == str[n][i]) {
          state = false;
          j_start_point = j+1;
        }
        if (answer[j] > str[n][i]) {
          answer.insert(j, 1, str[n][i]);
          if(state) {
            j_start_point = j+1;
          }
          // cout << ";"+answer << " " << start_point << " " << j_start_point << "\n";
          break;
        }
        if (!state && answer[j] != str[n][i]) {
          state = true;
        }
      }
      if (j == answer.length()) {
        answer += str[n][i];
        if(state) {
          j_start_point = j+1;
        }
        // cout << ":"+answer << " " << start_point << " " << j_start_point << "\n";
      }
    }
  }
}

void print()
{
  cout << answer << "\n";
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