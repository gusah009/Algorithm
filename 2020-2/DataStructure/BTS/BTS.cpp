#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define L node->left
#define R node->right


int N, depth;
string state, name;
bool exist;

typedef struct tree{
  tree* left;
  tree* right;
  string name;
} Tree;

void insertNode(Tree* node)
{
  if (node->name == "") {
    node->name = name;
    L = new Tree;
    R = new Tree;
  } else {
    if (name < node->name) {
      insertNode(L);
    } else {
      insertNode(R);
    }
  }
}

Tree* findNode(Tree* root)
{
  Tree* node;
  if (root->name == name) {
    return root;
  } else {
    if (root->left->name != "") {
      node = findNode(root->left);
      if (node != nullptr) return node;
    }
    if (root->right->name != "") {
      node = findNode(root->right);
      if (node != nullptr) return node;
    }
  }
  return nullptr;
}

bool isLeaf(Tree* node)
{
  if (L->name == "" && R->name == "") {
    return true;
  }
  return false;
}

string deleteNode(Tree* node, Tree* parent, char dir)
{
  if (dir == 'L') {
    if (R->name == "") {
      string ret = node->name;
      if (parent->name == name) parent->left = L;
      else parent->right = L;
      delete node;
      return ret;
    }
    return deleteNode(R, node, 'L');
  } else {
    if (L->name == "") {
      string ret = node->name;
      if (parent->name == name) parent->right = R;
      else parent->left = R;
      delete node;
      return ret;
    }
    return deleteNode(L, node, 'R');
  }
}

void printNode(int depth, Tree* node)
{
  if (node->name == "") {
    return;
  }
  if (depth == 1) {
    exist = false;
    cout << node->name << " ";
    return;
  }
  printNode(depth - 1, L);
  printNode(depth - 1, R);
}

void printLeaf(Tree* node)
{
  if (node->name == "") {
    return;
  }
  if (isLeaf(node)) {
    cout << node->name << " ";
    return;
  }
  printLeaf(L);
  printLeaf(R);
}

void input_solve()
{
  cin >> N;
  Tree* root = new Tree;
  root->left = new Tree;
  root->right = new Tree;
  FOR(n, N) {
    cin >> state;
    if (state == "+") {
      cin >> name;
      insertNode(root);
    } else if (state == "-") {
      cin >> name;
      Tree* node = findNode(root);
      if (node != nullptr) {
        if (isLeaf(node)) {
          node->name = "";
          delete L;
          delete R;
        } else {
          if (L->name != "") {
            node->name = deleteNode(L, node, 'L');
          } else {
            node->name = deleteNode(R, node, 'R');
          }
        }
      }
    } else if (state == "depth") {
      cin >> depth;
      exist = true;
      printNode(depth, root);
      if (exist) cout << "NO\n";
      else       cout << "\n";
    } else {
      printLeaf(root);
      cout << "\n";
    }
  }
}

int main()
{
  input_solve();
}