#include <iostream>
#include <cstdio>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    double pie = 3.1415926535897932384626433832795028;
    double R;
    cin >> R;

    printf("%.6f\n", pie*R*R);
    printf("%.6f", 2*R*R);
    return 0;
}