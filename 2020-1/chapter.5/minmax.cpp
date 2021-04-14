#include <iostream>
#define INF 987654321

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    int min = INF, max = -INF, input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if(input < min) {
            min = input;
        }
        if(input > max) {
            max = input;
        }
    }
    cout << min << " " << max;
    return 0;
}