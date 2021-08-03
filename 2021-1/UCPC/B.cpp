#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int arr1[31][31];
int arr2[31][31];
int moving[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int diff1, diff2, diff_n, diff_m;
bool flag = true;

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    FOR(m, M) {
      cin >> arr1[n][m];
    }
  }
  FOR(n, N) {
    FOR(m, M) {
      cin >> arr2[n][m];
      if (flag && arr1[n][m] != arr2[n][m]) {
        flag = false;
        diff_n = n;
        diff_m = m;
        diff1 = arr1[n][m];
        diff2 = arr2[n][m];
      }
    }
  }
}

void check(int n, int m) {
  arr1[n][m] = diff2;
  FOR(i, 4) {
    int new_n = n + moving[i][0];
    int new_m = m + moving[i][1];

    if (0 <= new_n && new_n < N) {
      if (0 <= new_m && new_m < M) {
        if (arr1[new_n][new_m] == diff1) {
          check(new_n, new_m);
        }
      }
    }
  }
}

void solve()
{
  // cout << '\n';
  // FOR(n, N) {
  //   FOR(m, M) {
  //     cout << arr1[n][m] << " ";
  //   }
  //   cout << '\n';
  // }

  if (!flag) {
    check(diff_n, diff_m);
  }
  
  // FOR(n, N) {
  //   FOR(m, M) {
  //     cout << arr1[n][m] << " ";
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';
}

void print()
{
  FOR(n, N) {
    FOR(m, M) {
      if (arr1[n][m] != arr2[n][m]) {
        cout << "NO" << "\n";
        return;
      }
    }
  }
  cout << "YES" << '\n';
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