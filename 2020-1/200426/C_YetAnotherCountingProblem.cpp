#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main() {
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int a, b, Q;
    cin >> a >> b >> Q;
    for(int q = 0; q < Q; q++) {
      long long no_count = 0;
      long long count;
      long long li, ri;
      cin >> li >> ri;
      count = ri - li + 1;

      int i_lcm = lcm(a, b);
      no_count += ((ri - li) / i_lcm) * max(a, b);
      if((li%i_lcm) > (ri%i_lcm)) {
        if((li%i_lcm) <= max(a,b) && (ri%i_lcm) <= max(a,b)) {
          no_count += max(a,b) - ((li%i_lcm) - ri%i_lcm - 1);
        }
        else if((li%i_lcm) >= max(a,b) && (ri%i_lcm) < max(a,b)) {
          no_count += (ri%i_lcm) + 1;
        }
        else {
          no_count += max(a,b);
        }
      }
      else {
        if((li%i_lcm) < max(a,b) && (ri%i_lcm) < max(a,b)) {
          no_count += (ri%i_lcm) - (li%i_lcm) + 1;
        }
        else if((li%i_lcm) <= max(a,b) && (ri%i_lcm) >= max(a,b)) {
          no_count += max(a,b) - (li%i_lcm);
        }
      }
      cout << count - no_count << " ";
    }
    cout << "\n";
  }
}