#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, result = 0;
    bool exist[26];
    bool answer = true;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string input;



    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int k = 0; k < 26; k++) {
            exist[k] = false;
        } 
        cin >> input;
        for(int j = 0; j < input.length(); j++) {
            for(int k = 0; k < 26; k++) {
                if(input[j] == alphabet[k]) {
                    if(exist[k] == false) {
                        exist[k] = true;
                    }
                    else {
                        if(input[j - 1] != alphabet[k]) {
                            answer = false;
                        }
                    }
                }
            }
        }
        if(answer == true) {
            result++;
        }
        answer = true;
    }
    cout << result;
    return 0;
}