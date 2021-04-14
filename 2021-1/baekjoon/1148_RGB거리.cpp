/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int RGB[3][1001];
int DP[3][1001] = {0};

int main()
{
    cin >> N;
    FOR (n, N) {
        cin >> RGB[0][n] >> RGB[1][n] >> RGB[2][n];
    }
    
    FOR(i, 3) {
        DP[i][0] = RGB[i][0];
    }
    
    FOR(i, 3) {
        DP[i][1] = min(RGB[(i + 1) % 3][0], RGB[(i + 2) % 3][0]) + RGB[i][1];
    }
    
    
    for (int n = 2; n < N; n++) {
        FOR(i, 3) {
            DP[i][n] = min(DP[(i + 1) % 3][n - 1], DP[(i + 2) % 3][n - 1]) + RGB[i][n];
        }
    }
    
    cout << min(min(DP[0][N - 1], DP[1][N - 1]), DP[2][N - 1]) << "\n";
    return 0;
}