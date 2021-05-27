#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321

int N;
string sik;
int num[10];
char oper;

vector<vector<int> > choice;
long long answer = -INF;

void GetCaseCount(int remain, int v, vector<int> arr)
{
  if (remain == 0) {
    FOR(j, arr.size()) {
      if (arr[j] >= 3) return;
    }
    choice.push_back(arr);
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

  if (N == 1) {
    cout << sik[0] - '0' << '\n';
    return 0;
  }
  vector<int> arr;
  GetCaseCount(N/2 + 1, N/2, arr);

  FOR(i, choice.size()) {
    do {
      long long result = 0;
      oper = 'X';
      int n = 0;
      FOR(j, choice[i].size()) {
        long long res = 0;
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
        if (oper == 'X') {
          result = res;
        } else if (oper == '+') {
          result += res;
        } else if (oper == '-') {
          result -= res;
        } else if (oper == '*') {
          result *= res;
        }
        if (n == N) {
          break;
        } else {
          oper = sik[n++];
        }
      }
      // FOR(j, choice[i].size()) {
      //   cout << choice[i][j] << ' ';
      // }
      // cout << result << '\n';
      // cout << '\n';
      
      answer = answer < result ? result : answer;
    } while(prev_permutation(choice[i].begin(), choice[i].end()));
  }

  cout << answer << '\n';
}