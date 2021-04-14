#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int n, r, C, rCheck = 0;
int gift[20] = {0};
bool answerState = false;
vector<int> solution;

bool cmp(int a, int b) {
  return a > b;
}

void input()
{
  cin >> n >> r;
  FOR(i, n) {
    cin >> gift[i];
  }
  cin >> C;
}

void solve(int index, int result, vector<int> x)
{
  if (index == n - 1) {
    if ((C - result) > 0) {
      if ((C - result) % gift[index] == 0) {
        x[index] = (C - result) / gift[index];
        solution = x;
        rCheck++;
      }
      if (rCheck == r) {
        answerState = true;
      }
    }
    return;
  }
  result += x[index] * gift[index];
  // solve(index - 1,x);
  while(!answerState) {
    if (result > C) {
      break;
    }
    solve(index + 1, result, x);
    x[index] += 1;
    result += gift[index];
  }
}

void print()
{
  if (!answerState) {
    cout << "NONE\n";
  } else {
    FOR(i, n) {
      cout << solution[i] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  vector<int> x(20, 1);
  solve(0, 0, x);
  print();
}