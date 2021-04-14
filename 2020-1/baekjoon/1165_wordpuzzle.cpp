#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string str;
int count = 0;
string num[24830];
int ans[24830];

void input()
{
  string filePath = "test.txt";

  num[0] = "AARGH";
  ans[0] = 0;
  int j = 0;
  for (int i = 1; i < 24830; i++) {
    cin >> str;
    num[i] = str;
    
    for(j = 0; num[i-1][j] == num[i][j]; j++) {}
    ans[i] = j;

    str = str.substr(j);
    num[i] = str;
  }

  ofstream writeFile(filePath.data());
  for (int i = 1; i < 24830; i++) {
    writeFile << ans[i] << " " << num[i] << "\n";
  }
}

void solve()
{

}

void print()
{

}

int main()
{
  input();
  solve();
  print();
}