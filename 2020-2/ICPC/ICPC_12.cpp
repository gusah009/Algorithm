#include <iostream>
#include <string>
using namespace std;

int main()
{
  int N, i, j, k = 0;
  char coin1, coin2;
  bool answer = true;
  string str1, str2;
  cin >> N;
  cin >> str1 >> str2;
  cin >> i >> j;
  coin1 = str1[i];
  str1.erase(i, 1);
  coin2 = str1[j-1];
  str1.erase(j-1, 1);
  str1 += 'P';
  str1 += 'Q';
  for (int n = 0; n < N; n++) {
    if (k == 1 && str1[n] != str2[n]) {
      if (str2[n] == coin2) {
        str1.insert(n, 1, coin2);
      } else {
        answer = false;
        break;
      }
    }
    if(k == 0 && str1[n] != str2[n]) {
      if (str2[n] == coin1) {
        str1.insert(n, 1, coin1);
        k++;
      } else {
        if (n > 0 && str2[n-1]  == coin1 && str2[n] == coin2) {
          str1.insert(n-1, 1, coin1);
          str1.insert(n, 1, coin2);
          break;
        } else {
          answer = false;
          break;
        }
      }
    }
  }
  for (int n = 0; n < N; n++) {
    if (str1[n] != str2[n]) {
      answer = false;
      break;
    }
  }
  if (answer) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}