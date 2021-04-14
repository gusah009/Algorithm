#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string input;
    int result = 0;

    cin >> input;
    for(int i = 0; i < input.length(); i++) {
        for(int j = 0; j < 18; j++) {
            if(input[i] == alphabet[j]) {
                result += j/3 + 2 + 1;
            }
        }
        if(input[i] == 'S') {
            result += 8;
        }
        for(int j = 19; j < 22; j++) {
            if(input[i] == alphabet[j]) {
                result += 9;
            }
        }
        for(int j = 22; j < 26; j++) {
            if(input[i] == alphabet[j]) {
                result += 10;
            }
        }
    }
    cout << result;
    return 0;
}