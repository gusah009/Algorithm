#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, ans = 0;
    string input;

    cin >> N;
    cin >> input;
    for(int i = 0; i < N; i++) {
        ans += (int)input[i] - '0';
    }

    cout << ans;

    return 0;
}