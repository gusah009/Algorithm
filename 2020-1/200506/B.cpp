#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int ui;

int main() {
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  vector<ui> DP;
  DP.push_back(2);
  for (ui j = 1; DP[j - 1] < 1000000001; j++) {
    DP.push_back(DP[j - 1] + 2 * (j + 1) + j);
  }

  ui T;
  cin >> T;
  for (ui t = 0; t < T; t++) {
    ui count = 0;
    ui n, i = 1;
    cin >> n;

    while(1) {
      for(i = 0; DP[i] <= n; i++) {
      }
      if(i == 0) {
        break;
      }
      else {
        count++;
        n -= DP[i-1];
      }
    }
    cout << count << "\n";
  }

}