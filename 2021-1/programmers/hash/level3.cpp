#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

unordered_map<string, map<int ,int> > sing;

vector<int> solution(vector<string> genres, vector<int> plays) {
  FOR(index, genres.size()) {
    sing[genres[index]].insert(make_pair(plays[index], index));
  }

  for (auto it = sing.begin(); it != sing.end(); it++) {
    
  }
  vector<int> answer;
  return answer;
}