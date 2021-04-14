#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input;
    int count = 0;
    bool whitespace = false;

    getline(cin,input);
    for(int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            if (count == 0) {
                count++;
            }
            whitespace = false;
        }
        if(whitespace == false) {
            if(count != 0 && input[i] == ' ') {
                count++;
                whitespace = true;
            }
        }
    }

    if(input[input.length()-1] == ' ') {
        if(input.length() != 1) {
            count--;
        }
    }

    cout << count;
    return 0;
}