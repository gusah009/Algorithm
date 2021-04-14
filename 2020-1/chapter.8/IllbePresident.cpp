#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, k, n;
    int people[15][15];
    for(int i = 0; i < 15; i++) {
        for(int j = 1; j < 15; j++) {
            if(i == 0) {
                people[i][j] = j;
            }
            else if (j == 1) {
                people[i][j] = 1;
            }
            else {
                people[i][j] = people[i - 1][j] + people[i][j - 1];
            }
        }
    }
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> k >> n;
        cout << people[k][n] << "\n";
    }
    return 0;
}