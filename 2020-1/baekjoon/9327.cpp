#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int N, E;
int Si[100];
bool exist[400001] = {0};

void input_solve()
{
  cin >> T;
  for (int t = 0; t < T; t++) {
    vector<int> vec(1);
    
    cin >> N >> E;
    for (int n = 0; n < N; n++) {
      cin >> Si[n];
      Si[n] *= 2;
    }

    for (int n = 0; n < N; n++) {
      int cur_size = vec.size();
      for (int i = 0; i < cur_size; i++) {
        if (exist[vec[i] + Si[n]] == false) {
          vec.push_back(vec[i] + Si[n]);
          exist[vec[i] + Si[n]] = true;
        }
      }
    }

    sort(vec.begin(), vec.end());
    
    bool state = true;
    for (int i = 0; i < vec.size(); i++) {
      if (state && vec[i] >= E) {
        cout << vec[i]/2 << "\n";
        state = false;
      }
      exist[vec[i]] = false;
    }
    if (state)
      cout << "FULL\n";
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve();
}