#include <iostream>
#include <vector>

using namespace std;

int T;
vector<string> str;
vector<string> answer;
string test;
bool yes_or_no = false;

void input()
{
  cin >> T;
  for (int t = 0; t < T; t++) {
    string tmp;
    cin >> tmp;
    str.push_back(tmp);
  }
}

void pattern_check(int i, bool state)
{
  // cout << "i: " << i << "\n";
  if(i >= test.length()) {
    yes_or_no = true;
    return;
  }

  if(state) { // 01
    if(test[i+1] == '1') {
      pattern_check(i + 2, test[i + 2] == '0');
    }
    else {
      return;
    }
  }
  else { // 100+1+
    if (i + 3 >= test.length()) { // 최소한의 1001도 못만들기 때문에 X
      return;
    }
    int j;
    if(test[i+1] == '0' && test[i+2] == '0') { // 100
      for (j = 3; i + j < test.length() && test[i+j] != '1'; j++) {} // 100+
      if (i + j == test.length() && test[i+j-1] == '0') { // 100+1 에서 1이 없으므로 X
        return;
      }
      j++;
      for (;i + j < test.length() && test[i+j] != '0'; j++) { //100+1+
        state = true; // 100+1뒤에 1이 하나라도 있으면
      }  // 마지막 1은 100+1+의 시작일 수도 있고 끝일수도 있음
      if (state) {
        pattern_check(i + j - 1, false); // 100~
        pattern_check(i + j, true); // 01
      }
      else {
        pattern_check(i + j, true); // 01
      }
    }
    else {
      return;
    }
  }
}

void solve()
{
  //패턴: (100+1+ | 01)+ 
  for (int t = 0; t < T; t++) {
    test = str[t];
    int i = 0;
    pattern_check(i, test[i] == '0');
    if (yes_or_no == true) {
      answer.push_back("YES");
    }
    else {
      answer.push_back("NO");
    }
    yes_or_no = false;
  }
}

void result()
{
  for (int t = 0; t < T; t++) {
    cout << answer[t] << "\n";
  }
}

int main()
{
  input();
  solve();
  result();
}