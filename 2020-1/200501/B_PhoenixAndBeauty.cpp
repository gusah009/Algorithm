#include <iostream>
#include <algorithm>
#include <math.h>


using namespace std;

int main() {
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int N, K;
    int a[100];
    bool is_diff[101];
    int diff_count = 0;
    for(int i = 0; i < 101; i++) {
      is_diff[i] = false;
    }
    cin >> N >> K;
    for (int n = 0; n < N; n++) {
      cin >> a[n];
      if(is_diff[a[n]] == false) {
        is_diff[a[n]] = true;
        diff_count++;
      }
    }
    if(diff_count > K) {
      cout << "-1";
    }
    else {
      cout << N * K << "\n";
      for(int i = 0; i < N; i++) {
        int last = 0;
        for(int j = 1; j < 101; j++) {
          if(is_diff[j]) {
            cout << j << " ";
            last = j;
          }
        }
        for(int j = 0; j < K - diff_count; j++) {
          cout << last << " ";
        }
      }
    }
    cout << "\n";
  }
}