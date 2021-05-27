#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N;
string sik;
int num[10];
char oper;

int init[10];
int dp[11];
vector<vector<int> > choice;
int answer = 0;

void GetCaseCount(int remain, int v, vector<int> arr)
{
  if (remain == 0) {
    choice.push_back(arr);
    FOR(i, arr.size()) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }
  if (remain < v)
    v = remain;
  int sum = 0;
  while (v)
  {
    arr.push_back(v);
    GetCaseCount(remain - v, v, arr);
    arr.pop_back();
    v--;
  }
}

int main()
{
  cin >> N;
  cin >> sik;
  int i = 0;

  FOR(i, 10)
  {
    init[i] = 1;
  }

  for (int n = 0; n < N; n += 2)
  {
    num[i++] = sik[n] - '0';
  }

  vector<int> arr;
  GetCaseCount(N/2 + 1, N/2, arr);

  FOR(i, choice.size()) {
    do {
      int result = 0;
      oper = 'X';
      FOR(j, choice[i].size()) {
        for (int n = 0; n < N;) {
          int res = 0;
          char op = 'X';
          FOR(k, choice[i][j] * 2 - 1) {
            if (k % 2 == 0) {
              if (op == 'X') {
                res = sik[n] - '0';
              } else if (op == '+') {
                res += sik[n] - '0';
              } else if (op == '-') {
                res -= sik[n] - '0';
              } else if (op == '*') {
                res *= sik[n] - '0';
              }
            } else {
              op = sik[n];
            }
            n++;
          }
          if (sik[n++] == 'X') {
            result = res;
          } else if (sik[n++] == '+') {
            result += res;
          } else if (sik[n++] == '-') {
            result -= res;
          } else if (sik[n++] == '*') {
            result *= res;
          }
        }
      }
      answer = answer < result ? result : answer;
    } while(next_permutation(choice[i].begin(), choice[i].end()));
  }

  cout << answer << '\n';
}