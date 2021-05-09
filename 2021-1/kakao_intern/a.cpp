#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string word_list[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            answer = answer * 10 + (s[i] - '0');
        }
        else {
            for (int j = 0; j < 10; j++) {
                if (word_list[j][0] == s[i] && word_list[j][1] == s[i + 1]) {
                    i += word_list[j].size() - 1;
                    answer = answer * 10 + j;
                    break;
                }
            }
        }
    }
    return answer;
}