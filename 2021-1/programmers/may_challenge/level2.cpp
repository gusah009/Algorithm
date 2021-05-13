#include <string>
#include <vector>
#include<stdio.h>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++) {
        long long j = numbers[i] + 1;
        while(true) {
            int count = __builtin_popcount(numbers[i] ^ j);
            if (count == 1 || count == 2) {
                answer.push_back(j);
                break;
            }
            j++;
        }
    }
    return answer;
}