#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int exist[26];
    cin >> input;

    for(int i = 0; i < 26; i++) {
        exist[i] = -1;
    }

    for(int i = 0; i < input.length(); i++) {
        for(int j = 0; j < alphabet.length(); j++) {
            if(exist[j] == -1 && input[i] == alphabet[j]) {
                exist[j] = i;
                break;
            }
        }
    }
    
    for(int i = 0; i < 26; i++) {
        cout << exist[i] << " ";
    }
    return 0;
}