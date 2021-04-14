#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int ui;

int main() {
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int N, k;
  cin >> N >> k;
  vector<int> a(N);
  
  for (int n = 0; n < N; n++) {
    cin >> a[n];
  }

}