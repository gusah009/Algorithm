/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N, M;
vector<pair<int, int> > tree[1001];

int findDist(int a, int prev_a, int b, int d) {
    if (a == b) {
        return d;
    }
    FOR(i, tree[a].size()) {
        if (tree[a][i].first != prev_a) {
            int result = findDist(tree[a][i].first, a, b, d + tree[a][i].second);
            if (result != -1) {
                return result;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    FOR(n, N - 1) {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back(make_pair(b, d));
        tree[b].push_back(make_pair(a, d));
    }
    FOR(m, M) {
        int a, b;
        cin >> a >> b;
        cout << findDist(a, -1, b ,0) <<'\n';
    }
    return 0;
}
