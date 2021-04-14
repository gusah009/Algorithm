#include <iostream>
#include <cmath>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y, w, h;
    int a, b;
    cin >> x >> y >> w >> h;

    a = h - y < y ? h - y: y;
    b = w - x < x ? w - x : x;

    cout << (a < b ? a : b);

    return 0;
}