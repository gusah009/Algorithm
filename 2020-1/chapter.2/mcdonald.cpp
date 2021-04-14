#include <iostream>
#define INF 987654321;

using namespace std;

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int burger[3];
    int soda[2];
    int min = INF;

    for(int i = 0; i < 3; i++) {
        cin >> burger[i];
    }

    for(int i = 0; i < 2; i++) {
        cin >> soda[i];
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            if(min > burger[i] + soda[j]) {
                min = burger[i] + soda[j];
            }
        }
    }

    cout << min - 50;
    return 0;
}