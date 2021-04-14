#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T, R;
    string S;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> R >> S;
        for (int i = 0; i < S.length(); i++) {
            cout << string(R, S[i]);
        }
        cout << "\n";
    }
    return 0;
}