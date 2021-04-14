#include <iostream>
#define INF 987654321;

using namespace std;

bool is_star[2187][2187];
int input;

void blank(int N, int y, int x) {
    int xx = x;
    if(N == 1) {
        is_star[y][x] = false;
    }
    else {
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                is_star[y][x] = false;
            }
            x++;
        }
        x = xx;
        y++;
    }
}

void star(int N, int y, int x) {
    int xx = x;
    //cout << "??\n";
    if(N == 1) {
        is_star[y][x] = true;
        return;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) {
                blank(N/3, y, x);
            }
            else {
                star(N/3, y, x);
            }
            x += N/3;
        }
        x = xx;
        y += N/3;
    }
    return;
}

void output()
{
    for (int i = 0; i < input; i++) {
        for (int j = 0; j < input; j++) {
            if(is_star[i][j])
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> input;
    star(input, 0, 0);

    output();
    return 0;
}