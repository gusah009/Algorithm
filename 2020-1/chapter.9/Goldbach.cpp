#include <iostream>
#include <cmath>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    int n;
    bool isPrime[10001];

    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i < 10001; i++) {
        isPrime[i] = true;
        for(int j = 2; j <= sqrt((double)i); j++) {
            if(i%j == 0) {
                isPrime[i] = false;
                break;
            }
        }
    }
    for(int i = 4; i < 10001; i++) {

    }

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = n/2; i > 1; i--) {
            if(isPrime[i] == true) {
                if(isPrime[n - i] == true) {
                    cout << i << " " << n - i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}