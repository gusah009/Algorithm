#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define FOR(i, j, k) for(int i = j; i < k; i++)

string genomeFile = "./sapiens.txt";
string genome = "";

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream readFile;
  readFile.open(genomeFile);
  if (readFile.is_open()) {
    string str;
    getline(readFile, str); // first line skip
    while (!readFile.eof()) {
      getline(readFile, str);
      genome += str;
    }
  }
  readFile.close();

  int N;
  cin >> N;
  FOR(n, 0, N) {
    string str;
    int src, dest;
    cin >> str >> src >> dest;
    int len = dest - src + 1;
    
    if (src <= genome.length()) {
      if (str == "front") {
        string select = genome.substr(src - 1, len);
        genome.replace(src - 1, len, "");
        genome = select + genome;
      } else if (str == "back") {
        string select = genome.substr(src - 1, len);
        genome.replace(src - 1, len, "");
        genome += select;
      } else if (str == "cut") {
        genome.replace(src - 1, len, "");
      } else if (str == "double") {
        string select = genome.substr(src - 1, len);
        genome.insert(dest, select);
        // cout << "GENOME: " << genome << "\n";
      } else if (str == "flip") {
        string select = genome.substr(src - 1, len);
        reverse(select.begin(), select.end());
        genome.replace(src - 1, len, select);
      } else if (str == "report") {
        string select = genome.substr(src - 1, len);
        cout << select << "\n";
      }
    } else {
      if (str == "report") {
        cout << "NONE\n";
      }
    }
  }

}