#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

set<string> phone_numbers;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), greater<string>());

    FOR (i, phone_book.size()) {
      if (phone_numbers.find(phone_book[i]) != phone_numbers.end()) {
        answer = false;
        break;
      }

      string tmp = "";
      FOR (j, phone_book[i].size()) {
        tmp += phone_book[i][j];
        phone_numbers.insert(tmp);
      }
    }

    return answer;
}