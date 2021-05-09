#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

bool table[1000000] = {0};
vector<int> del;

string solution(int n, int k, vector<string> cmd) {
    FOR(c, cmd.size()) {
        if (cmd[c].size() >= 3) {
            if (cmd[c][0] == 'D') {
                int len = stoi(cmd[c].substr(2));
                for (int i = 0; i < len;) {
                    k++;
                    if (!table[k]) {
                        i++;
                    }
                }
            } else {
                int len = stoi(cmd[c].substr(2));
                for (int i = 0; i < len;) {
                    k--;
                    if (!table[k]) {
                        i++;
                    }
                }
            }
        } else {
            if (cmd[c][0] == 'C') {
                table[k] = 1;
                del.push_back(k);
                bool flag = true;
                for (int i = k + 1; i < n; i++) {
                    if (!table[i]) {
                        k = i;
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int i = k - 1; i >= 0; i--) {
                        if (!table[i]) {
                            k = i;
                            break;
                        }
                    }
                }
            } else {
                table[del.back()] = 0;
                del.pop_back();
            }
        }
    }
    string answer = "";
    FOR(i, n) {
        answer += !table[i] ? 'O' : 'X';
    }
    return answer;
}