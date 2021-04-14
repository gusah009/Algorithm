#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int answer = 0;
vector<int> human[51];

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    int tmp;
    cin >> tmp;
    if (tmp != -1) {
      human[tmp].push_back(n);
    }
  }
}

int DFS(int node, int depth)
{
  if (human[node].size() == 0) {
    return 1;
  } 
  int maximum = -1;
  for (int i = 0; i < human[node].size(); i++) {
    maximum = max(maximum, DFS(human[node][i], depth + 1));
  }
  cout << "size" << maximum + human[node].size() << "\n";
  return maximum + human[node].size();
}
void solve()
{
  cout << DFS(0, -1) << "\n";
}

void print()
{
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}