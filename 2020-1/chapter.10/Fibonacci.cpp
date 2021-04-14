#include <iostream>
#define INF 987654321;

using namespace std;

int fibonacci(int N) {
    if(N == 0) {
        return 0;
    }
    if(N == 1) {
        return 1;
    }
    return fibonacci(N-1) + fibonacci(N-2);
}

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    cout << fibonacci(N);

    return 0;
}