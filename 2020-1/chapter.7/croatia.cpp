#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input;
    int result = 0;

    cin >> input;
    for(int i = 0; i < input.length(); i++) {
        if (input[i] == 'c') {
            if (input[i + 1] == '=') {
                result++;
                i++;
            }
            else if (input[i + 1] == '-') {
                result++;
                i++;
            }
            else {
                result++;
            }
        }
        else if (input[i] == 'd') {
            if (input[i + 1] == 'z') {
                if (input[i + 2] == '=') {
                    result++;
                    i++;
                    i++;
                }
                else {
                    result++;
                }
            }
            else if (input[i + 1] == '-') {
                result++;
                i++;
            }
            else {
                result++;
            }
        }
        else if(input[i] == 'l') {
            if(input[i + 1] == 'j') {
                result++;
                i++;
            }
            else {
                result++;
            }
        }
        else if(input[i] == 'n') {
            if(input[i + 1] == 'j') {
                result++;
                i++;
            }
            else {
                result++;
            }
        }
        else if(input[i] == 's') {
            if(input[i + 1] == '=') {
                result++;
                i++;
            }
            else {
                result++;
            }
        }
        else if(input[i] == 'z') {
            if(input[i + 1] == '=') {
                result++;
                i++;
            }
            else {
                result++;
            }
        }
        else {
            result++;
        }
    }
    cout << result;
    return 0;
}