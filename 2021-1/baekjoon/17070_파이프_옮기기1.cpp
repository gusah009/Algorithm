/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

#define FOR(i, j) for (int i = 0; i < j; i++)

int N;
int board[17][17];
int dir[3][2] = {{1, 0}, {1, 1}, {0, 1}};
int answer = 0;

using namespace std;
// prev 가로, 세로, 대각선

void DFS(int y, int x, int prev)
{
    if (y == N - 1 && x == N - 1) {
        answer++;
        return;
    }
    
    FOR(i, 3) {
        if (prev == 0) {
            if (i == 0) {
                if (x + 1 < N)
                    if (board[y][x + 1] != 1) DFS(y, x + 1, i);
            } else if (i == 2) {
                if (x + 1 < N && y + 1 < N)
                    if (board[y + 1][x + 1] != 1 &&
                        board[y][x + 1] != 1 &&
                        board[y + 1][x] != 1
                    ) DFS(y + 1, x + 1, i);
            }
        } else if (prev == 1) {
            if (i == 1) {
                if (y + 1 < N)
                    if (board[y + 1][x] != 1) DFS(y + 1, x, i);
            } else if (i == 2) {
                if (x + 1 < N && y + 1 < N)
                    if (board[y + 1][x + 1] != 1 &&
                        board[y][x + 1] != 1 &&
                        board[y + 1][x] != 1
                    ) DFS(y + 1, x + 1, i);
            }
            
        } else if (prev == 2){
            if (i == 0) {
                if (x + 1 < N)
                    if (board[y][x + 1] != 1) DFS(y, x + 1, i);
            } else if (i == 1) {
                if (y + 1 < N)
                    if (board[y + 1][x] != 1) DFS(y + 1, x, i);
            } else if (i == 2) {
                if (x + 1 < N && y + 1 < N)
                    if (board[y + 1][x + 1] != 1 &&
                        board[y][x + 1] != 1 &&
                        board[y + 1][x] != 1
                    ) DFS(y + 1, x + 1, i);
            }
        }
    }
}

int main()
{
    cin >> N;
    FOR(i, N) {
        FOR(j, N) {
            cin >> board[i][j];
        }
    }
    
    DFS(0, 1, 0);
    
    cout << answer << '\n';
    return 0;
}
