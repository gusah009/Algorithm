/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

long long N, page[6];
long long total = 0;
long long result = 0;
long long maximum = -1;
long long minimum1 = 987654321;
long long minimum2 = 987654321;
long long minimum3 = 987654321;

int main()
{
    cin >> N;
    for(int i = 0; i < 6; i++) {
        cin >> page[i];
        minimum1 = min(page[i], minimum1);
        maximum = max(page[i], maximum);
        total += page[i];
    }
    
    if (N == 1) {
        cout << total - maximum;
        return 0;
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if ((2.5 - i) != -(2.5 - j)) {
                minimum2 = min(page[i] + page[j], minimum2);
            }
        }
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                if ((2.5 - i) != -(2.5 - j) && (2.5 - i) != -(2.5 - k) && (2.5 - j) != -(2.5 - k)) {
                    minimum3 = min(page[i] + page[j] + page[k], minimum3);
                }
            }
        }
    }    
    
    result += minimum3 * 4;
    result += minimum2 * (8 * N - 12);
    result += minimum1 * ((N - 2) * (N - 2) + (N - 1) * (N - 2) * 4);
    cout << result;
    return 0;
}
