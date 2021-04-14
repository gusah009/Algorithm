#include <iostream>
#define INF 987654321;

using namespace std;

bool HanSu(int i) {
    if(i < 100) {
        return true;
    }

    if(i == 1000) {
        return false;
    }

    int result[3];
    for(int j = 0; j < 3; j++) {
        result[j] = i % 10;
        i /= 10;
    }
    if(result[2] - result[1] == result[1] - result[0]) {
        return true;
    }
    return false;
}

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, result = 0;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        if(HanSu(i)) {
            result++;
        }
    }
    cout << result;
    return 0;
}