#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int M, N;
    int number;
    int min;
    int sum = 0;
    bool isPrime[10001];

    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i < 10001; i++) {
        isPrime[i] = true;
        for(int j = 2; j <= i/2; j++) {
            if(i%j == 0) {
                isPrime[i] = false;
                break;
            }
        }
    }

    cin >> M >> N;
    for(int i = M; i <= N; i++) {
        if(isPrime[i] == true) {
            min = i;
            break;
        }
    }

    for(int i = M; i <= N; i++) {
        if(isPrime[i] == true) {
            sum += i;
        }
    }
    if(sum == 0) {
        cout << -1;
    }
    else {
        cout << sum << "\n";
        cout << min;
    }
    return 0;
}