#include <iostream>
#include <map>
#include <utility>

using namespace std;
#define NMAX 500000

int N, M;
//map<int, int> dset;
int *dset;

void make_set(int ssize){
  dset = new int[ssize];
  for(int s=0; s<ssize; s++){
    dset[s] = -1; // no root
  }
}
int find_root(int a){
  int root = a;
  while(dset[root] != -1){
    root = dset[root];
  }
  if(dset[a] != -1) dset[a] = root;
  return root;
}

void union_set(int a, int b){
  int a_root = find_root(a);
  int b_root = find_root(b);
  if(a_root == b_root) return;
  dset[b_root] = a_root;
}

bool find_set(int a, int b){
  int a_root = find_root(a);
  int b_root = find_root(b);
  if(a_root == b_root) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  make_set(N);
  int ans = 0;
  for(int m=0; m<M; m++){
    int a, b;
    cin >> a >> b;
    if(ans) continue;
    if(find_set(a,b)){
      ans = m+1;
    }
    else union_set(a,b);
  }
  cout << ans;
  return 0; 
}