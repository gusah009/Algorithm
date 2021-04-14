#include <iostream>

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c, result, x[10];
    cin >> a >> b >> c;
    result = a*b*c;
    
    for(int i = 0; i < 10; i++) {
        x[i] = 0;
    }

    while(result != 0) {
        x[result%10]++;
        result = result/10;
    }
    
    for(int i = 0; i < 10; i++) {
        cout << x[i] << "\n";
    }
    
    return 0;
}