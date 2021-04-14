#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 

int main(){
  int n; 
  cin >> n; 
  vector<int> v; 
  int w; 
  for(int i = 0; i < 2*n; i++){
    cin >> w; 
    v.push_back(w); 
  }
  sort(v.begin(), v.end()); 

  //int last = 2*n - 1; 
  int a = 0; 
  int b = 2*n - 1; 
  vector<int> sum; 
  for(int i = 0; i < n; i++){
    sum.push_back(v[a] + v[b]); 
    a++; 
    b--; 
  }

  sort(sum.begin(), sum.end()); 
  cout << sum[0] << endl; 

  return 0; 
}