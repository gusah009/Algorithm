#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int> > V[100001];

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    int tmp, tmp2 = 0, dist;
    cin >> tmp;
    while(tmp != -1) {
      cin >> tmp2;
      if (tmp2 == -1) {
        break;
      }
      cin >> dist;
      V[tmp].push_back(make_pair(tmp2, dist));
    }
  }
}

pair<int, int> DFS(int node, int prev_node)
{
  pair<int, int> max_dist(node, 0);
  if (V[node].size() == 0) {
    return make_pair(node, 0);
  }
  for (int n = 0; n < V[node].size(); n++) {
    if (V[node][n].first != prev_node) {
      pair<int, int> new_node = DFS(V[node][n].first, node);
      if(new_node.second + V[node][n].second > max_dist.second) {
        max_dist = new_node;
        max_dist.second += V[node][n].second;
      }
    }
  }
  return max_dist;
}

void solve()
{
  // DFS 두번으로 트리의 지름을 알아낸다.
  // https://koosaga.com/14
  cout << DFS(DFS(2, -1).first, -1).second << "\n";
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