#include <iostream>
#include <algorithm>
#define INF 987654321;

using namespace std;

#define endl "\n"
#define MAX 51
using namespace std;
 
int Arr[MAX];
int Select[MAX];
int T, N, K, P;
int plates[51][31];
int maxim = 0;
bool check = false;
 
void DFS(int Cnt, int tot)
{
  if (Cnt == N)
  {
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += Select[i];
    }
    if(sum != P) {
      return;
    }
    else {
      check = true;
      int total = 0;
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < Select[i]; j++) {
          total += plates[i][j];
        }
      }
      if(maxim < total) {
        maxim = total;
      }
      return;
    }
    // cout << " { ";
    // for (int i = 0; i < N; i++)
    // {
    //     cout << Select[i] << " ";
    // }
    // cout << "} " << endl;
      return;
  }
  for (int i = 0; i <= K; i++)
  {
    Select[Cnt] = Arr[i];
    DFS(Cnt + 1, tot + Select[Cnt]);
    if(tot + Select[Cnt] >= P) {
      break;
    }
    if(check == true) {
      check = false;
      break;
    }
  }
}


int main() {  
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < MAX; i++) Arr[i] = i;

  cin >> T;
  for(int t = 0; t < T; t++) {
    maxim = 0;
    cin >> N >> K >> P;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < K; j++) {
        cin >> plates[i][j];
      }
    }
    DFS(0, 0);
    cout << "Case #" << t+1 << ": " << maxim << "\n";
  }
  
  return 0;
}