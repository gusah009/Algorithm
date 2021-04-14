#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> tmp_answer[11];
int cour[11] = {0};

void solve(vector<char> cook, int index, int count, vector<string> orders, vector<int> course)
{
    if (index == cook.size()) {
        int ans = 0;
        for (int a = 0; a < course.size(); a++) {
            if (course[a] == count) {
                for (int i = 0; i < orders.size(); i++) {
                    int si = 0;
                    for (int j = 0; j < orders[i].size(); j++) {
                        for (int k = 0; k < cook.size(); k++) {
                            if (cook[k] == orders[i][j]) {
                                si++;
                            }
                        }
                    }
                    if (si == count) {
                        ans++;
                    }
                }
                string answ = "";
                for (int i = 0; i < cook.size(); i++) {
                    if(cook[i]) {
                        answ += cook[i];
                    }
                }
                if (ans >= 2) {
                    if (cour[count] < ans) {
                        cour[count] = ans;
                        tmp_answer[count].clear();
                        tmp_answer[count].push_back(answ);
                    } 
                    else if (cour[count] == ans) {
                        tmp_answer[count].push_back(answ);
                    }
                }
                break;
            }
        }
        return;
    }
    solve(cook,index + 1, count + 1, orders, course);
    cook[index] = 0; 
    solve(cook,index + 1, count, orders, course);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> cook = {0};
    bool exist[26] = {0};
    int index = -1;
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].length(); j++) {
            exist[orders[i][j] - 'A'] = true;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (exist[i]) {
            cook.push_back(('A'+i));
        }
    }
    
    solve(cook, 0, 0, orders, course);
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < tmp_answer[i].size(); j++) {
            answer.push_back(tmp_answer[i][j]);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}