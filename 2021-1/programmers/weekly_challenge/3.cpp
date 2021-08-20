#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX_PUZZLE_SIZE 6
#define INF 987654321

class puzzle
{
public:
  bool use = false;
  vector<pair<int, int> > data[4];
  void rotate()
  {
    sort(data[0].begin(), data[0].end());
    // FOR(j, data[0].size()) {
    //   cout << data[0][j].first << ' ' << data[0][j].second << ", ";
    // }
    // cout << '\n';

    for (int i = 1; i < 4; i++) {
      int max_x = -INF;
      int max_y = -INF;
      FOR(j, data[i - 1].size()) {
        int puzzle_x = data[i - 1][j].first;
        int puzzle_y = data[i - 1][j].second;
        int new_puzzle_x = (puzzle_y);
        int new_puzzle_y = -(puzzle_x);
        data[i].push_back(make_pair(new_puzzle_x, new_puzzle_y));
        max_y = max(max_y, new_puzzle_y);
      }
      FOR(j, data[i].size()) {
        if (data[i][j].second == max_y) {
          max_x = max(max_x, data[i][j].first);
        }
      }

      FOR(j, data[i].size()) {
        data[i][j].first -= max_x;
        data[i][j].second -= max_y;
      }

      sort(data[i].begin(), data[i].end());

      // FOR(j, data[i].size()) {
      //   cout << data[i][j].first << ' ' << data[i][j].second << ", ";
      // }
      // cout << '\n';
    }
    // cout << '\n';
  }

  bool operator==(const puzzle &other) const
  {
    if (data[0].size() != (other.data)[0].size()) return false;
    FOR(i, 4) {
      bool flag = true;
      FOR(j, data[i].size()) {
        if (data[i][j].first != (other.data)[0][j].first ||
            data[i][j].second != (other.data)[0][j].second) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return true;
        break;
      }
    }
    return false;
  }
};



int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int N;
vector<puzzle> puzzles;
vector<vector<int>> global_game_board, global_table;

void make_puzzle_table(int first_i, int first_j,
                 int i, int j,
                 puzzle *newPuzzle)
{
  global_table[i][j] = 0;

  (newPuzzle->data)[0].push_back(make_pair(first_j - j, first_i - i));
  FOR(k, 4) {
    int next_i = i + d[k][0];
    int next_j = j + d[k][1];
    if (0 <= next_i && next_i < N &&
        0 <= next_j && next_j < N) {
      if (global_table[next_i][next_j] == 1) {
        make_puzzle_table(first_i, first_j,
                    next_i, next_j, newPuzzle);
      }
    }
  }
}

void make_puzzle_game_board(int first_i, int first_j,
                 int i, int j,
                 puzzle *newPuzzle)
{
  global_game_board[i][j] = 1;

  (newPuzzle->data)[0].push_back(make_pair(first_j - j, first_i - i));
  FOR(k, 4) {
    int next_i = i + d[k][0];
    int next_j = j + d[k][1];
    if (0 <= next_i && next_i < N &&
        0 <= next_j && next_j < N) {
      if (global_game_board[next_i][next_j] == 0) {
        make_puzzle_game_board(first_i, first_j,
                    next_i, next_j, newPuzzle);
      }
    }
  }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
  N = game_board.size();
  global_game_board = game_board;
  global_table = table; 

  int answer = 0;

  FOR(i, global_table.size()) {
    FOR(j, global_table[i].size()) {
      if (global_table[i][j] == 1) {
        puzzle newPuzzle;
        make_puzzle_table(i, j, i, j, &newPuzzle);
        newPuzzle.rotate();
        puzzles.push_back(newPuzzle);
      }
    }
  }

  FOR(i, global_game_board.size()) {
    FOR(j, global_game_board[i].size()) {
      if (global_game_board[i][j] == 0) {
        puzzle blankPuzzle;
        make_puzzle_game_board(i, j, i, j, &blankPuzzle);
        sort((blankPuzzle.data)[0].begin(), (blankPuzzle.data)[0].end());
        
        // FOR(j, (blankPuzzle.data)[0].size()) {
        //   cout << (blankPuzzle.data)[0][j].first << ' ' << (blankPuzzle.data)[0][j].second << ", ";
        // }
        // cout << '\n';

        FOR(p, puzzles.size()) {
          if (!puzzles[p].use) {
            if (puzzles[p] == blankPuzzle) {
              puzzles[p].use = true;
              answer += puzzles[p].data[0].size();
              break;
            }
          }
        }
      }
    }
  }
  return answer;
}