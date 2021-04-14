#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    unsigned int x, y;
    unsigned int sum = 0;
    int i;
    
    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> x >> y;
        for(i = 1; sum < y - x; i++) {
            sum += (i+1)/2;
        }
        sum = 0;
        cout << i - 1 << "\n";
    }
    return 0;
}