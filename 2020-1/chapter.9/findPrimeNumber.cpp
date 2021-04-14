#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    int number;
    int sum = 0;
    bool isPrime[1001];

    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i < 1001; i++) {
        isPrime[i] = true;
        for(int j = 2; j <= i/2; j++) {
            if(i%j == 0) {
                isPrime[i] = false;
                break;
            }
        }
    }

    cin >> N;
    for(int n = 0; n < N; n++) {
        cin >> number;
        if(isPrime[number] == true) {
            sum++;
        }
    }

    cout << sum;
    return 0;
}