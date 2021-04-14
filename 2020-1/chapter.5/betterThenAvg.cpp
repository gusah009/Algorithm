#include <iostream>
#include <cstdio>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    int score[1000];
    cin >> C;
    for(int c = 0; c < C; c++) {
        int N;
        int total = 0;
        int result = 0;
        cin >> N;
        for(int n = 0; n < N; n++) {
            cin >> score[n];
            total += score[n];
        }
        for(int n = 0; n < N; n++) {
            if(score[n] > (float)total/N) {
                result++;
            }
        }
        printf("%.3f\%\n", (float)result/N*100);
    }

    return 0;
}