/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

int M;
bool S[21] = {0};

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> M;
  FOR(m, M) {
    string str;
    int n;
    cin >> str;
    if (str != "all" && str != "empty") cin >> n;
    if (str == "add") {
      S[n] = true;
    } else if (str == "remove") {
      S[n] = false;
    } else if (str == "check") {
      cout << S[n] << '\n';
    } else if (str == "toggle") {
      S[n] = !S[n];
    } else if (str == "all") {
      FOR(i, 20) {
        S[i + 1] = true;
      }
    } else if (str == "empty") {
      FOR(i, 20) {
        S[i + 1] = false;
      }
    }
  }
  
  return 0;
}