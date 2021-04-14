#include <iostream>
#include <cmath>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int M, N;
    bool isPrime;

    cin >> M >> N;
    for(int i = M; i <= N; i++) {
        isPrime = true;
        for(int j = 2; j <= sqrt((double)i); j++) {
            if(i%j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime == true && i != 1) {
            cout << i << "\n";
        }
    }

    return 0;
}