#include <iostream>
#include <string>
#include <vector>
using namespace std;

int DP[20001];

int solution(vector<string> strs, string T)
{
    for (int i = 0; i < 20001; i++) {
        DP[i] = 1987654321;
    }
    for (int t = 0; t < T.size(); t++) {
        for (int i = 0; i < strs.size(); i++) {
            int last = strs[i].size() - 1;
            if (strs[i][last] == T[t]) {
                if (t > strs[i].size() - 1) {
                    if (DP[t - (strs[i].size())] != 0) {
                        bool flag = true;
                        for (int j = 0; j < strs[i].size(); j++) {
                            if (T[t - j] != strs[i][last - j]) flag = false;
                        }
                        if (flag) {
                            DP[t] = min(DP[t - (strs[i].size())] + 1, DP[t]);
                        }
                    }
                } else if (t == strs[i].size() - 1) {
                    bool flag = true;
                    for (int j = 0; j < strs[i].size(); j++) {
                        if (T[t - j] != strs[i][last - j]) flag = false;
                    }
                    if (flag) {
                        DP[t] = 1;
                    }
                }
            }
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // for (int t = 0; t < T.size(); t++) {
    //     cout << DP[t] << endl;
    // }
    if (DP[T.size() - 1] == 1987654321) return -1;
    return DP[T.size() - 1];
}