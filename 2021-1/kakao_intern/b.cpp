#include <string>
#include <vector>

#define FOR(i, j) for (int i = 0; i < j; i++)

using namespace std;

int moving[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<string> board;

bool isOk(int i, int j)
{
    // 상하좌우 체크
    FOR(a, 4) {
        int next_i = i + moving[a][0];
        int next_j = j + moving[a][1];
        if (0 <= next_i && next_i <= 4 && \
            0 <= next_j && next_j <= 4 ) {
            if (board[next_i][next_j] == 'P') {
                return false;
            }
        }
    }
    FOR(a, 4) {
        FOR(b, 4) {
            if (a != (b + 2) % 4) {
                int next_i = i + moving[a][0] + moving[b][0];
                int next_j = j + moving[a][1] + moving[b][1];
                if (0 <= next_i && next_i <= 4 && \
                    0 <= next_j && next_j <= 4 ) {
                    if (board[next_i][next_j] == 'P') {
                        if (board[next_i - moving[a][0]][next_j - moving[a][1]] != 'X' || \
                            board[next_i - moving[b][0]][next_j - moving[b][1]] != 'X') {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    FOR(i, places.size()) {
        board = places[i];
        bool ok = true;
        FOR(j, places[i].size()) {
            FOR(k, places[i][j].size()) {
                if (places[i][j][k] == 'P') ok = isOk(j, k);
                if (!ok) {
                    break;
                }
            }
            if (!ok) break;
        }
        ok ? answer.push_back(1) : answer.push_back(0);
    }
    return answer;
}