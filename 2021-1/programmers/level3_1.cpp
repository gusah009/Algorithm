#include <string>
#include <vector>

using namespace std;

int DP[60000];

int solution(int N) {
    int answer = 0;
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    
    for (int n = 3; n <= N; n++) {
        DP[n] = (DP[n - 1] + DP[n - 2]) % 1000000007;
    }
    answer = DP[N];
    return answer;
}