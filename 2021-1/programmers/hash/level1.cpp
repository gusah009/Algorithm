#include <string>
#include <vector>
#include <unordered_map>

using namespace std;



string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> completion_set;
    for (int i = 0; i < completion.size(); i++) {
      if (completion_set.find(completion[i]) == completion_set.end()) {
        completion_set.insert(make_pair(completion[i], 0));
      } else {
        completion_set[completion[i]]++;
      }
    }
    for (int i = 0; i < participant.size(); i++) {
      if (completion_set.find(participant[i]) == completion_set.end()) {
        answer = participant[i];
        break;
      } else {
        completion_set[participant[i]]--;
      }
    }

    if (answer == "") {
      for (auto it = completion_set.begin(); it != completion_set.end(); it++) {
        if (it->second != 0) {
          answer = it->first;
          break;
        }
      }  
    }

    return answer;
}