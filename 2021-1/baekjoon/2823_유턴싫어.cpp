/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

int R, C;
char board[10][10];
vector<int> EDGE[101];

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    cin >> R >> C;
    FOR(r, R) {
        FOR(c, C) {
            cin >> board[r][c];
        }
    }
    
    FOR(r, R) {
        FOR(c, C) {
            int index = r * C + c;
            if (board[r][c] == '.') {
                FOR(i, 4) {
                    if (0 <= r + dir[i][0] && r + dir[i][0] < R &&
                        0 <= c + dir[i][1] && c + dir[i][1] < C) {
                        if (board[r + dir[i][0]][c + dir[i][1]] == '.') {
                            EDGE[index].push_back((r + dir[i][0]) * C + c + dir[i][1]);
                        }
                    }
                }
            }
        }
    }
    
    int answer = 0;
    FOR (i, R * C) {
        if (EDGE[i].size() == 1) {
            cout << 1 << '\n';
            return 0;
        }
    }
    
    cout << 0 << '\n';
    return 0;
}