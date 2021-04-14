#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[51];
int del_node;
int answer = 0;

void input()
{
  cin >> N;
  for (int n = 0; n < N; n++) {
    int tmp;
    cin >> tmp;
    if (tmp != -1) {
      tree[tmp].push_back(n);
    }
    else {
      tree[50].push_back(n);
    }
  }
  cin >> del_node;
}

void delete_node(int node) {
  for (int i = tree[node].size() - 1; i >= 0; i--) {
    // cout << "del: " << tree[node][i] << "\n";
    delete_node(tree[node][i]);
    tree[node].pop_back();
  }
}

void search_node(int node)
{
  if (tree[node].size() == 0) {
    answer++;
    return;
  }
  for (int i = tree[node].size() - 1; i >= 0; i--) {
    // cout << "ser: " << tree[node][i] << "\n";
    search_node(tree[node][i]);
    tree[node].pop_back();
  }
}

void solve()
{
  if(del_node == 50) {
    search_node(50);
    return;
  }

  delete_node(del_node);
  for (int n = 0; n <= 50; n++) {
    for (int i = tree[n].size() - 1; i >= 0; i--) {
      if (tree[n][i] == del_node) {
        if (i == 0 && tree[n].size() == 2) {
          int tmp = tree[n][1];
          tree[n].pop_back();
          tree[n].pop_back();
          tree[n].push_back(tmp);
        }
        else {
          tree[n].pop_back();
        }
      }
    }
  }

  if (tree[50].size() == 0) {
    return;
  }
  else {
    search_node(50);
  }
}

void print()
{
  cout << answer << "\n";
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