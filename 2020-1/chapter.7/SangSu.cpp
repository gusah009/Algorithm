#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int A, B;
    cin >> A >> B;
    A = A % 10 * 100 + ((A / 10) % 10) * 10 + A / 100;
    B = B % 10 * 100 + ((B / 10) % 10) * 10 + B / 100;

    if(A > B) {
        cout << A;
    }
    else {
        cout << B;
    }
    return 0;
}