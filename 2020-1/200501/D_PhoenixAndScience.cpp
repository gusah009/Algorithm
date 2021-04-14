#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int num[100];

  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    ll N;
    cin >> N;
    vector<int> answer;
    vector<int> real_answer;

    if (N == 2) {
      cout << "1" << "\n";
      cout << "0" << "\n";
      continue;
    }
    else if(N == 3) {
      cout << "1" << "\n";
      cout << "1" << "\n";
      continue;
    }
    else if (N == 4) {
      cout << "2" << "\n";
      cout << "0 1" << "\n";
      continue;
    }

    if(N%2 == 0) {
      answer.push_back(0);
      N--;
    }
    answer.push_back(2);
    // real_answer.push_back(1);
    N--;
    N-=2;
    int i = 8;
    int sum = 4;
    for(; sum <= N ; i*=2) {
      sum += i;
      answer.push_back(i/2);
    }
    sum -= i/2;
    i /= 4;
    if(i <= N-sum) {
      answer.push_back(N-sum - i/2);
    }
    else {
      answer.pop_back();
      answer.push_back(N - sum);
      answer.push_back(0);
    }
    // for(; i != 1; i /= 2) {
    //   while(i <= N-sum) {
    //     sum += i;
    //     answer.push_back(i);
    //   }
    // }
    cout << answer.size() << "\n";
    for(vector<int>::iterator iter = answer.begin(); iter != answer.end(); ++iter) {
      cout << *iter/2 << " ";
    }
    cout << "\n";
  //   sort(answer.begin(), answer.end());
  //   for(vector<int>::iterator iter = answer.begin() + 1; iter != answer.end(); ++iter) {
  //     if(*iter == *(iter-1)) {
  //       real_answer.push_back(0);
  //     }
  //     else {
  //       real_answer.push_back((*iter)/2);
  //     }
  //   }
  //   cout << real_answer.size() << "\n";
  //   // for(vector<int>::iterator iter = answer.begin(); iter != answer.end(); ++iter) {
  //   //   cout << *iter << " ";
  //   // // }
  //   // cout << "\n";
  //   for(vector<int>::iterator iter = real_answer.begin(); iter != real_answer.end(); ++iter) {
  //     cout << *iter << " ";
  //   }
  //   cout << "\n";
  // }
  }
}