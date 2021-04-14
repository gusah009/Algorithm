#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int X;
    int sum = 0, i, j;
    cin >> X;
    
    for(i = 1; sum < X; i++) {
        sum += i;
    }

    for(j = 1; j < X - sum + i - 1; j++) {

    }

    if(i%2 == 0) {
        cout << i - j << "/" << j;
    }
    else{
        cout << j << "/" << i - j;
    }

    return 0;
}