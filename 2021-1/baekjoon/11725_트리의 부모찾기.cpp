/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

#define FOR(i,j) for(int i = 0; i < j; i++) 

using namespace std;

int N;
vector<int> tree[100001];
int answer[100001];

void DFS(int a, int prev_a) {
    answer[a] = prev_a;
    
    FOR(i, tree[a].size()) {
        if (tree[a][i] != prev_a) {
            DFS(tree[a][i], a);
        }
    }
}

int main()
{
    cin >> N;
    FOR(n, N - 1) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(1, -1);
    
    for (int i = 2; i <= N; i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
