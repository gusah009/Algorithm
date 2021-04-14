#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

vector< stack<int> > yard;
int N, max_height, min_height;

void input()
{
  cin >> N;
  FOR(n, N) {
    int M;
    stack<int> stmp;
    cin >> M;
    FOR(m, M) {
      int tmp;
      cin >> tmp;
      stmp.push(tmp);
    }
    yard.push_back(stmp);
  }
}

void find_height()
{
  max_height = -1;
  min_height = 987654321;
  FOR(n, N) {
    int height = yard[n].size();
    if (max_height < height) {
      max_height = height;
    }
    if (min_height > height) {
      min_height = height;
    }
  }
}

pair<int, int> find_max_container()
{
  pair<int, int> container;
  int id = -1;
  FOR(n, N) {
    if (yard[n].size() == max_height) {
      if (id < yard[n].top()) {
        id = yard[n].top();
        container = make_pair(id, n);
      }
    }
  } 
  return container;
}

void solve()
{
  find_height();
  while(max_height - min_height > 1) {
    pair<int, int> max_container = find_max_container();
    FOR(n, N) {
      if (yard[n].size() == min_height) {
        yard[max_container.second].pop();
        yard[n].push(max_container.first);
        break;
      }
    }
    find_height();
  }
}

void print(vector<stack<int>> yard)
{
  FOR(n, N) {
    cout << n+1 << " > ";
    stack<int> stmp;
    while(!yard[n].empty()) {
      stmp.push(yard[n].top());
      yard[n].pop();
    }
    while(!stmp.empty()) {
      cout << stmp.top() << " ";
      stmp.pop();
    }
    cout << "\n";
  }
}

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  input();
  solve();
  print(yard);
}