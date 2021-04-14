#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char answer;
    int count[26], max = -INF;
    cin >> input;

    for(int i = 0; i < 26; i++) {
        count[i] = 0;
    }

    for(int i = 0; i < input.length(); i++) {
        if(input[i] >= 'a') {
            input[i] -= 32;
        }
        for(int j = 0; j < alphabet.length(); j++) {
            if(alphabet[j] == input[i]) {
                count[j]++;
            }
        }
    }

    for(int i = 0; i < 26; i++) {
        if(max < count[i]) {
            max = count[i];
            answer = alphabet[i];
        }
        else if(max == count[i]) {
            answer = '?';
        }
    }

    cout << answer;
    return 0;
}