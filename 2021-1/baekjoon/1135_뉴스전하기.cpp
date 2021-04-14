/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N, result = 0;
vector<int> p[51];

void input()
{
    cin >> N;
    FOR(n, N) {
        int boss;
        cin >> boss;
        if (boss != -1) {
            p[boss].push_back(n);
        }
    }
}

int call(int n) {
    if (p[n].size() == 0) return 1;
    vector<int> v_t;
    int t = 0;
    FOR(i, p[n].size()) {
        v_t.push_back(call(p[n][i]));
    }
    sort(v_t.begin(), v_t.end(), greater<int>());
    
    int j = 0;
    while(accumulate(v_t.begin(), v_t.end(), 0) != 0) {
        j++;
        FOR(i, min(int(v_t.size()), j)) {
            if (v_t[i] != 0) v_t[i]--;
        }
    }
    return j + 1;
}

void solve()
{
    result = call(0);
}

void print()
{
    cout << result - 1 << '\n';
}

int main()
{
  input();
  solve();
  print();

  return 0;
}