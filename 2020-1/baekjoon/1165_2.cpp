#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string suffix[10] = {"MENT", "TION", "ABLE", "NESS", "AL", "ER", "OR", "ATE", "EN","IC"};
string str;
int ans[24830];
string num[24830];

int main()
{ 
  string filePath = "test2.txt";

  int j = 0;
  for (int i = 1; i < 24830; i++) {
    cin >> ans[i];
    cin >> str;
    num[i] = str;

    for (j = 0; j < 10; j++) {
      string::size_type f = str.find(suffix[j]);
      if (f != string::npos) {
        str.erase(f, suffix[j].length());
        char c_j = j + '0';
        str.insert(f, 1, c_j);
        num[i] = str;
        break;
      }
    }
  }
  
  ofstream writeFile(filePath.data());
  for (int i = 1; i < 24830; i++) {
    writeFile << ans[i] << " " << num[i] << "\n";
  }
}