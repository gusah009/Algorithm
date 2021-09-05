#include <string>
#include <vector>
#include <iostream>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

int N;
int answer = 0;

void bracket(int openNum, int closeNum) {
    if (openNum + closeNum == N * 2) {
        answer++;
        return;
    }
    if (openNum < N) bracket(openNum + 1, closeNum);
    if (openNum > closeNum) bracket(openNum, closeNum + 1);
}

int solution(int n) {
    N = n;
    bracket(0, 0);
    cout << answer << '\n';
    return answer;
}