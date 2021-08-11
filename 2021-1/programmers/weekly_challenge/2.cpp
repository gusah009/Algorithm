#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    FOR(index_this, scores.size()) {
        pair<int, bool> max_element = make_pair(-1, false);
        pair<int, bool> min_element = make_pair(INF, false);
        FOR(index_other, scores[index_this].size()) {
            if (max_element.first < scores[index_other][index_this]) {
                max_element.first = scores[index_other][index_this];
                max_element.second = false;
            } else if (max_element.first == scores[index_other][index_this]) {
                max_element.second = true;
            }
            if (min_element.first > scores[index_other][index_this]) {
                min_element.first = scores[index_other][index_this];
                min_element.second = false;
            } else if (min_element.first == scores[index_other][index_this]) {
                min_element.second = true;
            }
        }
        
        int score_sum = 0;
        double score_avg = 0;
        FOR(index_other, scores[index_this].size()) {
            score_sum += scores[index_other][index_this];
        }
        if (scores[index_this][index_this] == max_element.first 
            && max_element.second == false) {
            score_sum -= scores[index_this][index_this];
            score_avg = score_sum / (scores[index_this].size() - 1);
        } else if (scores[index_this][index_this] == min_element.first 
            && min_element.second == false) {
            score_sum -= scores[index_this][index_this];
            score_avg = score_sum / (scores[index_this].size() - 1);
        } else {
            score_avg = score_sum / scores[index_this].size();
        }
        
        if (score_avg >= 90) {
            answer += 'A';
        } else if (score_avg >= 80) {
            answer += 'B';
        } else if (score_avg >= 70) {
            answer += 'C';
        } else if (score_avg >= 50) {
            answer += 'D';
        } else {
            answer += 'F';
        }
    }
    
    return answer;
}