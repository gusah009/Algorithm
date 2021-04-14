#include <iostream>
#define INF 987654321;

using namespace std;


int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, G, R;
    int garden[50][50];
    cin >> N >> M >> G >> R;
    for(int n = 0; n < N; n++) {
        for(int m = 0; m < M; m++) {
            cin >> garden[n][m];
        }
    }
    return 0;
}