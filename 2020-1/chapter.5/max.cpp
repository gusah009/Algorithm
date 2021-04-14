#include <iostream>

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, result, max = 0;
    for (int i = 0; i < 9; i++) {
        cin >> N;
        if (N > max) {
            max = N;
            result = i + 1;
        }
    }
    cout << max << "\n" << result;
    return 0;
}