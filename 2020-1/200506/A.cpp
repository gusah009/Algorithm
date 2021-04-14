#include <iostream>

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n, m;
    cin >> n >> m;
    if(n == 1 || m == 1 || (m == 2 && n == 2)) {
      cout << "YES" << "\n";
    }
    else {
      cout << "NO" << "\n";
    }
  }

}