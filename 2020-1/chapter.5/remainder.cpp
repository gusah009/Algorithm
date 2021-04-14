#include <iostream>

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int input, result = 0;
    int remainder[42];

    for(int i = 0; i < 42; i++) {
        remainder[i] = 0;
    }

    for(int i = 0; i < 10; i++) {
        cin >> input;
        remainder[input%42]++;
    }

    for(int i = 0; i < 42; i++) {
        if(remainder[i] != 0) {
            result++;
        }
    }
    
    cout << result;
    return 0;
}