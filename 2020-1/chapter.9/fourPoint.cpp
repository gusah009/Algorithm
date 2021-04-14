#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a[3], b[3];
    for(int i = 0; i < 3; i++) {
        cin >> a[i] >> b[i];
    }
    if(a[0] != a[1]) {
        if(a[0] != a[2]) {
            cout << a[0];
        }
        else {
            cout << a[1];
        }
    }
    else {
        cout << a[2];
    }
    cout << " ";
    if(b[0] != b[1]) {
        if(b[0] != b[2]) {
            cout << b[0];
        }
        else {
            cout << b[1];
        }
    }
    else {
        cout << b[2];
    }

    return 0;
}