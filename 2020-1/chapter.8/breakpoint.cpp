#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int A, B, C;
    cin >> A >> B >> C;

    if(C <= B) {
        cout << -1;
    }
    else {
        cout << A / (C - B) + 1;
    }
    return 0;
}