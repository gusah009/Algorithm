#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N, M;
int arr[10];

int permutation(int n, int r)
{
  vector<int> vecInt;
  vector<int>::iterator vecIntIter;

  for (int ii = 0; ii < n; ii++)

    vecInt.push_back(arr[ii]);

  while (1)
  {
    for (int ii = 0; ii < r; ii++)
      printf("%d ", vecInt[ii]);
    printf("\n");

    reverse(vecInt.begin() + r, vecInt.end());

    if (!next_permutation(vecInt.begin(), vecInt.end()))
      break;
  }

  return 1;
}

void input()
{
  cin >> N >> M;
  FOR(n, N)
  {
    cin >> arr[n];
  }
  sort(arr, arr + N);
}

void solve()
{
  permutation(N, M);
}

void print()
{
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}