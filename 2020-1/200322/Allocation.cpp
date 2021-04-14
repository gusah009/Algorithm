#include <iostream>
#include <algorithm>
#define INF 987654321;

using namespace std;


int main() {  
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, A, B;
  int sort_price[100001];
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int sum = 0;
    int i = 0;
    cin >> N >> B;
    for(i = 0; i < N; i++) {
      cin >> sort_price[i];
    }
    sort(sort_price, sort_price + N);
    for(i = 0; sum <= B && i < N; i++){
      sum += sort_price[i];
    }
    if(sum <= B && i == N) {
      cout << "Case #" << t+1 << ": " << i << "\n";
    }
    else {
      cout << "Case #" << t+1 << ": " << i - 1 << "\n";
    }
  }
  return 0;
}