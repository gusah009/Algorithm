#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B, V;

    cin >> A >> B >> V;
    if(V==A) {
        cout << 1;
    }
    else {
        if((V-A)%(A-B) == 0) {
            cout << (V-A)/(A-B) + 1;
        }
        else {
            cout << (V-A)/(A-B) + 2;
        }
    }
    return 0;
}