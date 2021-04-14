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

int T, N, K, W;
int D[1001];
int DP[1001];
vector<int> rule[1001];
int result = 0;

void input() {
    FOR(i, 1001) {
        rule[i].clear();
        rule[i].shrink_to_fit();
        DP[i] = -1;    
    }
    
    cin >> N >> K;
    FOR(n, N) {
        cin >> D[n + 1];
    }
    FOR(k, K) {
        int start, end;
        cin >> start >> end;
        rule[end].push_back(start);
    }
    cin >> W;
}

int Func(int start) {
    if (DP[start] != -1) {
        return DP[start];
    }
    int minimum = 0;
    FOR(r, rule[start].size()) {
        minimum = max(minimum, Func(rule[start][r]));
    }
    DP[start] = minimum + D[start];
    // cout << start << " : " << DP[start] << '\n';
    return DP[start];
}

void solve() {
    result = 0;
    FOR(r, rule[W].size()) {
        result = max(result, Func(rule[W][r]));
    }
    result += D[W];
}

void print() {
    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    FOR(t, T) {
        input();
        solve();
        print();
    }
    return 0;
}