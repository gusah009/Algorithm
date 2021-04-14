#include <iostream>

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, X, result;
    int i = 0;

    cin >> N;
    result = N;
    do {
        X = N/10 + N%10;
        N = (N%10)*10 + X%10;
        i++;
    } while(result != N);
    cout << i;
    return 0;
}