#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string str;
int answer = 0;

void input() 
{
  cin >> N;
  cin >> str;
}

void solution(bool a[26], int n)
{
  if (n == N) {
    bool result;
    for (int i = 0; i < str.length(); i++) { 
      
      if (str[i] >= 'a' && str[i] <= 'z') {
        result = a[str[i] - 'a'];
      }        
      else if (str[i] == '0') {
        result = false;
      }
      else if (str[i] == '1') {
        result = true;
      }

      else if (str[i] == '=') {
        i++;
        i++;
        if (str[i] >= 'a' && str[i] <= 'z') {
          result = result == a[str[i] - 'a'];
        }        
        else if (str[i] == '0') {
          result = result == false;
        }
        else if (str[i] == '1') {
          result = result == true;
        }
      }
      else if (str[i] == '?') {
        if (result == false) {
          while(str[i] != ':') {
            i++;
          }
        }
      }
      else if (str[i] == ':') {
        break;
      }
    }
    if (result == false) {
      // cout << a[0] << " " << a[1] << "\n";
      answer++;
    }
    return;
  }
  a[n] = false;
  solution(a, n+1);
  a[n] = true;
  solution(a, n+1);
}

void solve() 
{
  bool a[26];
  solution(a, 0);
}

void print() 
{
  cout << answer << "\n";

}

int main()
{
  input();
  solve();
  print();
}