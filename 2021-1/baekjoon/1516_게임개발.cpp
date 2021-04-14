/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, result[501] = {0};
int building[501], DP[501] = {0};
vector<int> prev_b[501];

void input() {
    cin >> N;
    FOR(n, N) {
        int tmp;
        cin >> building[n + 1];
        while(1) {
            cin >> tmp;
            if (tmp == -1) break;
            prev_b[n + 1].push_back(tmp);
        }
    }
}

int Func(int start) {
    if (DP[start] != 0) return DP[start];
    int maximum = 0;
    FOR(r, prev_b[start].size()) {
        maximum = max(maximum, Func(prev_b[start][r]));
    }
    return DP[start] = maximum + building[start];
}

void solve() {
    FOR(n, N) {
        FOR(r, prev_b[n + 1].size()) {
            result[n] = max(result[n], Func(prev_b[n + 1][r]));
        }
        result[n] += building[n + 1];
    }
    
    // FOR(n, N) {
    //     FOR(r, prev_b[n + 1].size()) {
    //         cout << prev_b[n + 1][r] << ' ';
    //     }
    //     cout << '\n';
    // }
}

void print() {
    FOR(n, N) {
        cout << result[n] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    print();
    return 0;
}