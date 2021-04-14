#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int ui;

#define MAX 1987654321
int main() {
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  bool is_exist[200000];
  vector<int> a(200000);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n, i, j, minimum = MAX;
    bool answer = true;
    cin >> n;
    for (i = 0; i < 200000; i++) {
      is_exist[i] = 0;
      a[i] = 0;
    }
    for (i = 0; i < n; i++) {
      cin >> a[i];
      int md = i + a[i]%n;
      if (md < 0) {
        md += n;
      }
      //cout << md << "\n"; 
      minimum = min(minimum, (md));
      if(is_exist[md]) {
        cout << "NO" << "\n";
        answer = false;
        break;
      }
      else {
        is_exist[md] = true;
      }
    }
    if(answer) {
      for (j = minimum; j < minimum + n; j++) {
        if(!is_exist[j]) {
          cout << "NO" << "\n";
          answer = false;
          break;
        }
      }

      if(answer && i == (n) && j == (minimum + n)) {
        cout << "YES" << "\n";
      }
    }
  }
}