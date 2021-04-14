#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> card;

void solve()
{
  int answer = 0;
  int sum = 0;
  for(int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      for (int k = j+1; k < N; k++) {
        sum = card[i] + card[j] + card[k];
        if(sum <= M) {
          answer = answer > sum ? answer : sum;
        }
      }
    }
  }
  cout << answer;
}

void input()
{
  int tmp;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> tmp;
    card.push_back(tmp);
  }  
}

int main()
{
  input();
  solve();
}