#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
int N;

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    num.push_back(tmp);
  }

  sort(num.begin(), num.end());

  for(int i = 0; i < N; i++) {
    cout << num[i] << "\n";
  }
}
