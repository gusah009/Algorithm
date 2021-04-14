#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, k = 0;
    int result = 0;
    string input;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input;
        for(int j = 0; j < input.length(); j++) {
            if(input[j] == 'O') {
                k++;
                result += k;
            }
            else {
                k = 0;
            }
        }
        cout << result << "\n";
        k = 0;
        result = 0;
    }

    return 0;
}