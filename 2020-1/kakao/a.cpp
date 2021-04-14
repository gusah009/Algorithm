#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<string> a = {"dd", "aaaa", "aaab", "cca"};
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "\n";
  }
}