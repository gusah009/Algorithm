#include <iostream>
#include <cmath>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x1, y1, r1, x2, y2, r2;
    double r;
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        r = sqrt((double)(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        if(x1 == x2 && y1 == y2) {
            if(r1 == r2) {
                cout << -1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if(r == r1 + r2 || r1 == r + r2 || r2 == r + r1) {
            cout << 1 << "\n";
        }
        else if(r1 + r2 < r || r2 + r < r1 || r1 + r < r2) {
            cout << 0 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
    }

    return 0;
}