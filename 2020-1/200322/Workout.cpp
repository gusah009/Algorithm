#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321;

using namespace std;

int main() {  
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T, N, K;
  int training[100001];
  cin >> T;
  for(int t = 0; t < T; t++) {
    vector<int> interval;
    cin >> N >> K;
    for(int n = 0; n < N; n++) {
      cin >> training[n];
      if(n != 0) {
        interval.push_back(training[n] - training[n-1]);
      }
    }
    for(int k = 0; k < K; k++) {
      sort(interval.begin(),interval.end());
    // for(vector<int>::iterator iter = interval.begin(); iter != interval.end(); iter++){
		//   cout << *iter << ' ';
	  // }
	  // cout << endl;
      if(interval.back()%2 == 0) {
        if(interval.back() == 1) {
          break;
        }
        int tmp = interval.back()/2;
        interval.pop_back();
        interval.push_back(tmp);
        interval.push_back(tmp);
      }
      else {
        if(interval.back() == 1) {
          break;
        }
        int tmp1 = interval.back()/2;
        int tmp2 = interval.back()/2 + 1;
        interval.pop_back();
        interval.push_back(tmp1);
        interval.push_back(tmp2);
      }
    }
    sort(interval.begin(),interval.end());
    cout << "Case #" << t+1 << ": " << interval.back() << "\n";
  }
  return 0;
}