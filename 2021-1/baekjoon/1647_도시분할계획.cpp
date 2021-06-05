#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
vector<pair<int, pair<int, int> > > path;
int parent[100001];
bool chk;
int res = 0;
int lastW;

void input()
{
  cin >> N >> M;
  FOR(m, M) {
    int A, B, C;
    cin >> A >> B >> C;
    path.push_back(make_pair(C, make_pair(A, B)));
  }
  sort(path.begin(), path.end());
}

int find(int u)
{
    if (u == parent[u])
        return u;
 
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    chk = false;
    u = find(u);
    v = find(v);
 
    // 사이클 존재 여부 확인 코드
    if (u == v)
        return;
 
    parent[u] = v;
    chk = true;
}

void solve()
{  
  for (int i = 1; i <= N; i++) parent[i] = i;

  for (int i = 0; i < M; i++)
  {
      merge(path[i].second.first, path[i].second.second);
      
      if(chk) {
          res += path[i].first;
          lastW = path[i].first;
      }
  }
}

void print()
{
  cout << res - lastW << '\n';
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