#include <iostream>
#define INF 987654321;

using namespace std;

int num[10000];

void selfNumber(int i) {
    int result = i;
    if(i > 10000) {
        return;
    }
    num[i]++;
    while(i != 0) {
        result += i%10;
        i /= 10;
    }
    selfNumber(result);
    return;
}

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 1; i < 10000; i++) {
        num[i] = -1;
    }

    for(int i = 1; i < 10000; i++) {
        selfNumber(i);
    }

    for(int i = 1; i < 10000; i++) {
        if(num[i] == 0) {
            cout << i << "\n";
        }
    }
    return 0;
}