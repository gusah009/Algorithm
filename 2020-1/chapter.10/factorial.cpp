#include <iostream>
#define INF 987654321;

using namespace std;

int factorial(int N) {
    if(N == 0) {
        return 1;
    }
    return N * factorial(N - 1);
}

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    cout << factorial(N);

    return 0;
}