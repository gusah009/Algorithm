/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

int N;
int x, y;
int M;
vector<int> EDGE[101];
int answer = -1;

void DFS(int v, int prev_v, int depth)
{
    if (v == y) {
        answer = depth;
        return;
    }
    
    FOR(i, EDGE[v].size()) {
        if (EDGE[v][i] == prev_v) continue;
        if (answer != -1) return;
        DFS(EDGE[v][i], v, depth + 1);
    }
    return;
}

int main()
{
    cin >> N;
    cin >> x >> y;
    cin >> M;
    FOR(m, M) {
        int v1, v2;
        cin >> v1 >> v2;
        EDGE[v1].push_back(v2);
        EDGE[v2].push_back(v1);
    }
    
    FOR(i, EDGE[x].size()) {
        DFS(EDGE[x][i], x, 1);
    }
    // FOR(i, EDGE[y].size()) {
    //     DFS(EDGE[y][i], y, 1);
    // }
    cout << answer << '\n';
    
    return 0;
}