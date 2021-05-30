#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int T, M, C, I;
unsigned char arr[100001] = {0};
int pointer = 0;
string code;
string input;

int main()
{
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  cin >> T;
  FOR(t, T) {
    cin >> M >> C >> I;
    cin >> code;
    cin >> input;
    int i = 0;
    // FOR(i, I) {
    //   cin >> arr[I - i - 1];
    // }
    int isInf = 0;
    int curr_a, curr_b;

    FOR(c, C) {
      if (isInf >= 50000000) {
        cout << "Loops " << curr_a << " " << curr_b << '\n';
        break;
      } 
      isInf++;
      if (code[c] == '+') {
        arr[pointer]++;
      } else if (code[c] == '-') {
        arr[pointer]--;
      } else if (code[c] == '<') {
        pointer = (pointer + 1) % M;
      } else if (code[c] == '>') {
        pointer = (pointer - 1) % M;
      } else if (code[c] == '[') {
        if (arr[pointer] == 0) {
          curr_a = c;
          int pairCheck = 0;
          for (int a = c + 1; a < M; a++) {
            if (code[a] == '[') {
              pairCheck++;
            }
            if (code[a] == ']') {
              if (pairCheck == 0) {
                c = a;
                break;
              } else {
                pairCheck--;
              }
            }
          }
        }
      } else if (code[c] == ']') {
        if (arr[pointer] != 0) {
          curr_b = c;
          // c = curr_a;
          int pairCheck = 0;
          for (int a = c - 1; a >= 0; a--) {
            if (code[a] == ']') {
              pairCheck++;
            }
            if (code[a] == '[') {
              if (pairCheck == 0) {
                c = a;
                break;
              } else {
                pairCheck--;
              }
            }
          }
        }
      } else if (code[c] == '.') {

      } else if (code[c] == ',') {
        if (i < I) {
          arr[pointer] = input[i++];
        } else {
          arr[pointer] = 255;
        }
      }
    }
    if (isInf < 50000000) {
      cout << "Terminates\n";
    }
  }

}