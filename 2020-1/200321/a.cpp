#include <iostream>
#define INF 987654321;

using namespace std;

int sticker[101][10][10];
int N, M, K;
int x[100], y[100];
int maxim = 0;
int check_monunPaper[40][40];

void noBlank(int i, int j) {
    check_monunPaper[i][j] = -1;
    if(check_monunPaper[i + 1][j] == 1) {
        noBlank(i+1, j);
    }
    if(check_monunPaper[i][j + 1] == 1) {
        noBlank(i, j+1);
    }
    if(i!= 0 && check_monunPaper[i - 1][j] == 1) {
        noBlank(i - 1, j);
    }
    if(j!= 0 && check_monunPaper[i][j - 1] == 1) {
        noBlank(i, j - 1);
    }
}

bool checkFunc(bool monunPaper[40][40]) {
    bool check = false;
    if(N == 1 || M == 1) {
        return true;
    }
    for(int i = 0; i < N; i++) {
        if(monunPaper[i][0] == 1) {
            check = true;
            break;
        }
    }
    if(check == false) {
        return false;
    }
    check = false;
    for(int i = 0; i < N; i++) {
        if(monunPaper[i][M-1] == 1) {
            check = true;
            break;
        }
    }
    if(check == false) {
        return false;
    }
    check = false;
    for(int i = 0; i < M; i++) {
        if(monunPaper[0][i] == 1) {
            check = true;
            break;
        }
    }
    if(check == false) {
        return false;
    }
    check = false;
    for(int i = 0; i < M; i++) {
        if(monunPaper[N-1][i] == 1) {
            check = true;
            break;
        }
    }
    if(check == false) {
        return false;
    }
    
    for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 40; j++) {
            check_monunPaper[i][j] = monunPaper[i][j];
        }
    }

    for(int a = 0; a < N; a++) {
        if(monunPaper[a][0] == 1) {
            noBlank(a,0);
            for(int i = 0; i < 40; i++) {
                for(int j = 0; j < 40; j++) {
                    if(check_monunPaper[i][j] == 1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void rotation(int k) {
    bool rotate[10][10];
    for(int i = 0; i < x[k]; i++) {
        for(int j = 0; j < y[k]; j++) {
            rotate[i][j] = sticker[k][y[k] - j - 1][i];
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            sticker[k][i][j] = -1;
        }
    } //스티커 -1로 초기화

    for(int i = 0; i < x[k]; i++) {
        for(int j = 0; j < y[k]; j++) {
            sticker[k][i][j] = rotate[i][j];
        }
    }
}

void attach(int k, bool monunPaper[40][40]) {
    if(sticker[k][0][0] == -1) {
        for(int i = 0; i < 40; i++) {
            for(int j = 0; j < 40; j++) {
                check_monunPaper[i][j] = 0;
            }
        }
        if(checkFunc(monunPaper) == false) {
            return;
        }
        
        int count = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(monunPaper[i][j] == 1){
                    count++;
                }
            }
        }
        if(count > maxim) {
            maxim = count;
                //TEST===
    for(int ii = 0; ii < N; ii++) {
        for(int jj = 0; jj < M; jj++) {
            cout << monunPaper[ii][jj] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    //========
        }
        return;
    }
    bool original_monunPaper[40][40];
    for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 40; j++) {
            original_monunPaper[i][j] = monunPaper[i][j];
        }
    }
    for(int r = 0; r < 4; r++) {
        for(int i = 0; i <= N - x[k]; i++) {
            for(int j = 0; j <= M - y[k]; j++) {
                for(int a = i; a < i + x[k]; a++) {
                    for(int b = j; b < j + y[k]; b++) {
                        //TEST===
                        // for(int ii = 0; ii < N; ii++) {
                        //     for(int jj = 0; jj < M; jj++) {
                        //         cout << monunPaper[ii][jj] << " ";
                        //     }
                        //     cout << "\n";
                        // }
                        // cout << "\n";
                        //========
                        if(monunPaper[a][b] == 1) {
                            if(sticker[k][a-i][b-j] == 1) {
                                for(int i = 0; i < 40; i++) {
                                    for(int j = 0; j < 40; j++) {
                                        monunPaper[i][j] = original_monunPaper[i][j];
                                    }
                                }
                                goto EXIT;
                            }
                        }
                        else {
                            monunPaper[a][b] = sticker[k][a-i][b-j];
                        }
                    }
                }
                for(int kk = 1; k + kk <= K; kk++) {
                    attach(k+kk, monunPaper);
                }
                EXIT:
                for(int i = 0; i < 40; i++) {
                    for(int j = 0; j < 40; j++) {
                        monunPaper[i][j] = original_monunPaper[i][j];
                    }
                }
            }
        }
        swap(x[k], y[k]);
        rotation(k);
    }
}

int main() {  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    bool monunPaper[40][40];
    int exist[100];

    for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 40; j++) {
            monunPaper[i][j] = 0;
        }
    } //모눈종이 0으로 초기화

    for(int k = 0; k < 101; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                sticker[k][i][j] = -1;
            }
        } //스티커 -1로 초기화
    }

    cin >> N >> M >> K;

    for(int k = 0; k < K; k++) {
        cin >> x[k] >> y[k];
        if(x[k] > N && y[k] > N || y[k] > M && x[k] > M || x[k] > N && x[k] > M || y[k] > N && y[k] >> M) {
            for(int i = 0; i < x[k]; i++) {
                for(int j = 0; j < y[k]; j++) {
                    cin >> sticker[k][i][j];
                    sticker[k][i][j] = -1;
                }
            }
            K--;
            k--;
        }
        else {
            for(int i = 0; i < x[k]; i++) {
                for(int j = 0; j < y[k]; j++) {
                    cin >> sticker[k][i][j];
                }
            }
        }
    }
    attach(0, monunPaper);
    cout << maxim;
    return 0;
}