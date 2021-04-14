#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int T;
long long int a, b;
long long int last;
string answer = "";

long long int my_pow(long long int a, long long int n)
{
  long long int tmp = 1;
  for (long long int i = 0; i < n; i++) {
    tmp *= 10;
  }
  return tmp;
}

void input()
{
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> a >> b;
    answer = "";
    //solve
    last = a * my_pow(10, b);
    while (a <= 100 && b > 0) {
      a*= 10;
      b--;
    }
    // 98 - 10 / 3 (29 + 1) * 3
    // last -= (to_string(last).length() + 1) * ((last - (long long int)my_pow(10,(to_string(last).length() - 1))) / (to_string(last).length() + 1) + 1);
    if (a > 100) {
      while (last > 100) {
        // cout << last << " " << to_string(last).length()  << " " << my_pow(10,(to_string(last).length() - 1)) << "\n";
        // cout << (last - my_pow(10,(to_string(last).length() - 1))) << "\n";
        // cout << ((last - my_pow(10,(to_string(last).length() - 1))) / (to_string(last).length() + 1) + 1) << "\n";
        // cout << (to_string(last).length() + 1) * ((last - my_pow(10,(to_string(last).length() - 1))) / (to_string(last).length() + 1) + 1) << "\n";
        last -= (to_string(last).length() + 1) * ((last - (long long int)my_pow(10,(to_string(last).length() - 1))) / (to_string(last).length() + 1) + 1);
        cout << "1 " << last << "\n";
      }
    }
    cout << last << "\n";
    while (last > 0) {
      string tmp = to_string(last);
      tmp.insert(0, "-");
      last -= tmp.length();
      answer.insert(0, tmp);
      if (answer.length() > 30) {
        answer.erase(30);
      }
    }
    if (last == -1) {
      answer.erase( 0, 1 );
    }
    //print
    if (answer.length() >= 21) {
      for (int i = 0; i < 17; i++) {
        cout << answer[i];
      }
      cout << "...";
    }
    else {
      cout << answer;
    }
    cout << "\n";
  }
}

int main()
{
  input();
}