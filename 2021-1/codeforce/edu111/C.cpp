// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define FOR(i, j) for(int i = 0; i < j; i++)

// int T, N, arr[200001];
// bool isIncrease[200001] = {0};
// long long answer = 0;

// void input()
// {
//   cin >> N;
//   FOR(n, N) {
//     cin >> arr[n];
//   }
//   answer = N * (N + 1) / 2;
// }

// void solve()
// {
//   vector<vector<pair<int, int> > > incList;
//   // cout << "!" << '\n';
//   FOR(n, N) {
//     // cout << n << "\n";
//     bool flag = true;
//     FOR(i, incList.size()) {
//       if (incList[i][incList[i].size() - 1].first <= arr[n]) {
//         flag = false;
//         incList[i].push_back(make_pair(arr[n], n));
//       }
//     }
//     if (flag) {
//       vector<pair<int, int> > tmp;
//       tmp.push_back(make_pair(arr[n], n));
//       incList.push_back(tmp);
//     }
//   }

//   FOR(i, incList.size()) {
//     if (incList[i].size() >= 3) {
//       FOR(j, incList[i].size() - 2) {
//         int a = incList[i][j].second;
//         int b = N - incList[i][j + 2].second - 1;
//         answer -= (a + b + 1);
//       }
//     }
//   }

//   cout << "=================\n";
//   vector<vector<pair<int, int> > > dcrList;
//   FOR(n, N) {
//     // bool flag = true;
//     FOR(i, dcrList.size()) {
//       cout << dcrList[i][dcrList[i].size() - 1].first << ' ' << arr[n] << "!@!@\n";
//       if (dcrList[i][dcrList[i].size() - 1].first >= arr[n]) {
//         // flag = false;
//         dcrList[i].push_back(make_pair(arr[n], n));
//       }
//     }
//     // if (flag) {
//       vector<pair<int, int> > tmp;
//       tmp.push_back(make_pair(arr[n], n));
//       dcrList.push_back(tmp);
//     // }
//   }
  
  
//   FOR(i, dcrList.size()) {
//     if (dcrList[i].size() >= 3) {
//       FOR(j, dcrList[i].size() - 2) {
//         cout << dcrList[i][j].first << ' ';
//         int a = dcrList[i][j].second;
//         int b = N - dcrList[i][j + 2].second - 1;
//         answer -= (a + b + 1);
//       }
//       cout << '\n';
//     }
//   }
// }

// void print()
// {
//   cout << answer << '\n';
//   cout << '\n' << '\n';
// }

// int main()
// {
//   // ios_base :: sync_with_stdio(false);
//   // cin.tie(NULL);
//   // cout.tie(NULL);
//   cin >> T;
//   FOR(t, T) {
//     input();
//     solve();
//     print();
//   }
// }