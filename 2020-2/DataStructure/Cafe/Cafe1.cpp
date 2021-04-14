#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

vector<int> seat;

int main()
{
  int N, K;
  int num;
  cin >> N >> K;
  FOR(k, K) {
    cin >> num;

    auto it = seat.begin();
    bool check = true;
    for(it = seat.begin(); it != seat.end(); it++) {
      if (*it == num) {
        seat.erase(it);
        check = false;
        break;
      } 
    }
    if (check) {
      seat.push_back(num);
      sort(seat.begin(), seat.end());
      for(it = seat.begin(); *it < num; it++);
      cout << num << " ";
      if (it == seat.begin()) {
        cout << *(seat.end() - 1) << " ";
      } else {
        cout << *(it - 1) << " ";
      }
      if (it == seat.end() - 1) {
        cout << *(seat.begin()) << " ";
      } else {
        cout << *(it + 1) << " ";
      }
      cout << "\n";
    }
  }
}