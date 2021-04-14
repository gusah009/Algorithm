#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
#define FOR(i, j, k) for (int i = j; i < k; i++)

string tree[2], order[2];

void input()
{
  FOR(i, 0, 2) {
    cin >> order[i] >> tree[i];
  }
}

void Pre2Post(string inOrder, string preOrder) {
  if (preOrder.length() == 0) return;

  char root = preOrder[0];
  int treeSize = preOrder.size();
  int left = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
  int right = treeSize - left - 1;
  Pre2Post(inOrder.substr(0, left), preOrder.substr(1, left));
  Pre2Post(inOrder.substr(left + 1, treeSize), preOrder.substr(left + 1, treeSize));

  cout << root;
}

void Post2Pre(string inOrder, string postOrder) {
  if (postOrder.length() == 0) return;

  int treeSize = postOrder.size();
  char root = postOrder[treeSize - 1];
  int left = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
  int right = treeSize - left - 1;
  Pre2Post(inOrder.substr(0, left), postOrder.substr(1, left));
  Pre2Post(inOrder.substr(left + 1, treeSize), postOrder.substr(left + 1, treeSize));

  cout << root;
}

void solve()
{
  if (order[1] == "Preorder") { //output is PostOrder
    cout << "Postorder ";
    Pre2Post(tree[0], tree[1]);
  } else { //output is PreOrder
    cout << "Preorder ";
    Post2Pre(tree[0], tree[1]);
  }
}

int main()
{
  input();
  solve();
}