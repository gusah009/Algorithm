#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int D = 0, G = 0;
vector< vector<int> > pos(300001);
int n_count[300001] = { 0 };
int total_count[300001] = { 0 };
vector <bool> exist;
vector <pair < int, int > > dudu;

void input()
{
  cin >> N;
  for (int n = 0; n < N - 1; n++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    dudu.push_back(make_pair(tmp1, tmp2));
  }

  for (int n = 0; n < N - 1; n++) {
    total_count[dudu[n].first]++;
    total_count[dudu[n].second]++;
    if (dudu[n].first > dudu[n].second) {
      int tmp = dudu[n].first;
      dudu[n].first = dudu[n].second;
      dudu[n].second = tmp;
    }
  }
  sort(dudu.begin(), dudu.end());
  for (int n = 0; n < N - 1; n++) {
    pos[dudu[n].first].push_back(n);
    pos[dudu[n].second].push_back(n);
  
  }
  
  // int prev = 0, n;
  // int j = dudu[0].first;
  // pos[j] = 0;

  // for (n = 1; n < N - 1; n++) {
  //   if (dudu[n].first != dudu[n-1].first) {
  //     n_count[j] = n - prev;
  //     prev = n;
  //     j = dudu[n].first;
  //     pos[j] = n;
  //   }
  // }
  // n_count[j] = n - prev;
  // pos[dudu[N-2].first + 1] = N - 1;
}

void solve()
{
  // G구하기
  for (int n = 0; n <= N; n++) {
    if (total_count[n] >= 3) {
      G += total_count[n] * (total_count[n] - 1) * (total_count[n] - 2) / 6;
    }
  }
  // D구하기
  int j;
  for (int n = 0; n < N - 1; n++) {
    // 3. 1 2 -> n 1 -> 2 m
    D += (total_count[dudu[n].first] - 1) * (total_count[dudu[n].second] - 1);
    // j = n + 1;
    // // 2. 1 2 -> 1 n -> n ~
    // while(dudu[j].first == dudu[n].first) {
    //   D += total_count[dudu[j].second] - 1;
    //   j++;
    // }
    // // 1. 1 2 -> 2 n -> n ~
    // for (int i = 0; i < pos[dudu[n].second].size(); i++) {
    //   if (pos[dudu[n].second][i] > n) {
    //     if (dudu[pos[dudu[n].second][i]].first == dudu[n].second) {
    //       D += total_count[dudu[pos[dudu[n].second][i]].second] - 1;
    //     }
    //     else if (dudu[pos[dudu[n].second][i]].second == dudu[n].second) {
    //       D += total_count[dudu[pos[dudu[n].second][i]].first] - 1;
    //     }
    //   }
    // }
    // total_count[dudu[n].first]--;
    // total_count[dudu[n].second]--;
  }

  // for (int n = 0; n < N - 1; n++) {
  //   cout << dudu[n].first << " " << dudu[n].second << "\n";
  // }
}

void print()
{
  if (D > G * 3) {
    cout << "D\n";
  }
  else if (D < G * 3) {
    cout << "G\n";
  }
  else {
    cout << "DUDUDUNGA\n";
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}