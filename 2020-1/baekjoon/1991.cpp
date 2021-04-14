#include <iostream>
#include <vector>
using namespace std;

int N;
int node[26][2] = {0};

void input()
{
  cin >> N;
  char root, left, right;
  for (int n = 0; n < N; n++) {
    cin >> root >> left >> right;
    if (left != '.') {
      node[root - 'A'][0] = left - 'A';
    }
    if (right != '.') {
      node[root - 'A'][1] = right - 'A';
    }
  }
}

void preorder(int index) {
  cout << char(index + 'A');
  if (node[index][0] != 0) {
    preorder(node[index][0]);
  }
  if (node[index][1] != 0) {
    preorder(node[index][1]);
  }
}
void inorder(int index) {
  if (node[index][0] != 0) {
    inorder(node[index][0]);
  }
  cout << char(index + 'A');
  if (node[index][1] != 0) {
    inorder(node[index][1]);
  }
}
void postorder(int index) {
  if (node[index][0] != 0) {
    postorder(node[index][0]);
  }
  if (node[index][1] != 0) {
    postorder(node[index][1]);
  }
  cout << char(index + 'A');
}
void solve()
{
  preorder(0);
  cout << "\n";
  inorder(0);
  cout << "\n";
  postorder(0);
  cout << "\n";
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