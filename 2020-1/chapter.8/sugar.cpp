#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    if(N == 4 || N == 7) {
        cout << -1;
    }
    else if(N%5 == 0 || N%5 == 3) {
        cout << N/5 + (N%5)/3;
    }
    else if(N%5 == 1 || N%5 == 4) {
        cout << (N-5)/5 + (N%5+5)/3;
    }
    else if(N%5 == 2) {
        cout << (N-10)/5 + (N%5 + 10)/3;
    }

    return 0;
}