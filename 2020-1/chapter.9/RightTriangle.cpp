#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    while(true) {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) {
            break;
        }
        if(a > b) {
            if(a > c) {
                if(a*a == b*b + c*c) {
                    cout << "right" << "\n";
                }
                else {
                    cout << "wrong" << "\n";
                }
            }
            else {
                if(c*c == b*b + a*a) {
                    cout << "right" << "\n";
                }
                else {
                    cout << "wrong" << "\n";
                }
            }
        }
        else {
            if(b > c) {
                if(b*b == a*a + c*c) {
                    cout << "right" << "\n";
                }
                else {
                    cout << "wrong" << "\n";
                }
            }
            else {
                if(c*c == b*b + a*a) {
                    cout << "right" << "\n";
                }
                else {
                    cout << "wrong" << "\n";
                }
            }
        }
    }
    return 0;
}