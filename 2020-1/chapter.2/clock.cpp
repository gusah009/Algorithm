#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int H, M;
    cin >> H >> M;

    if (M >= 45) {
        cout << H << " " << M-45;
    }
    else {
        if(H == 0) {
            cout << 23 << " " << 60 - (45 - M);
        }
        else {
            cout << H - 1 << " " << 60 - (45 - M);
        }
    }

    return 0;
}