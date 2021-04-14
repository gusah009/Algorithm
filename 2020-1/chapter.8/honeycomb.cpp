#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, sum = -1;
    int i;
    cin >> N;
    if(N == 1) {
        cout << 1;
    }
    else {
        N -= 2;
        N /= 6;
        for(i = 1; sum < N; i++) {
            sum += i;
        }
        cout << i;
    }
    return 0;
}