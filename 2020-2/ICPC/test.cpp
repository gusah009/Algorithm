#include <iostream>

using namespace std;

int main()
{
  string str1 = "ABCDEFG";
  str1.insert(1,1, 'I');
  for (int i = 0; i < str1.size(); i++) {
    cout << str1[i];
  }
  cout << "\n";
}