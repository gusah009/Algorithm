#include <iostream>
#include <list>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    string input;
    bool is_same = true;
    int count = 0;
    cin >> input;

    for(int i = 1; i < input.length(); i++) {
      if(input[i - 1] != input[i]) {
        is_same = false;
      }
    }

    if(is_same) {
      cout << input;
    }
    else {
      if(input[0] == '0') {
        for(int i = 0; i < input.length()-1; i++) {
          cout << "01";
        }
      }
      else {
        for(int i = 0; i < input.length()-1; i++) {
          cout << "10";
        }
      }
    }
    cout << "\n";
  }
}