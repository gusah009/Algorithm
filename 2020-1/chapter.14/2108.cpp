#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num[8001] = {0};
vector<int> v_num;
int N;
int sum = 0;
int many = 0;
int answer;
bool state = false;

int devide()
{
  int ret_i = sum/N;
  float ret_f = ((float)sum)/N;
  if(ret_i >= 0) {
    if (ret_f - ret_i >= 0.5) {
      return ret_i + 1;
    }
    else {
      return ret_i;
    }
  }
  else {
    if (ret_i - ret_f >= 0.5) {
      return ret_i - 1;
    }
    else {
      return ret_i;
    }
  }
}

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    num[tmp+4000]++;
    sum += tmp;
  }
  cout << devide() << "\n";

  for (int i = 0; i < 8001; i++) {
    if(num[i] > 0) {
      if(many < num[i]) {
        many = num[i];
        answer = i - 4000;
        state = false;
      }
      else if (many == num[i] && state == false) {
        answer = i - 4000;
        state = true;
      }
      for (int j = 0; j < num[i]; j++) {
        v_num.push_back(i-4000);
      }
    }
  }
  cout << v_num[(N-1)/2] << "\n";
  cout << answer << "\n";
  cout << v_num[N-1] - v_num[0] << "\n";
}
