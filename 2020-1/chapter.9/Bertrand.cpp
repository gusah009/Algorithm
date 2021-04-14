#include <iostream>
#include <cmath>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N = 1;
    int sum = 0;
    bool isPrime;
    cin >> N;
    while(N != 0) {
        for(int i = N + 1; i <= 2*N; i++) {
            isPrime = true;
            for(int j = 2; j <= sqrt((double)i); j++) {
                if(i%j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime == true && i != 1) {
                sum++;
            }
        }
        cout << sum << "\n";
        sum = 0;
        cin >> N;
    }
    return 0;
}