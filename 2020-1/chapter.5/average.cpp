#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    int score, avg;
    int max = -INF;
    int total = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> score;
        if(max < score) {
            max = score;
        }
        total += score;
    }

    cout << ((float)total/max)*100/N;
    return 0;
}