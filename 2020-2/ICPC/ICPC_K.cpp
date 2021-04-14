#include <iostream> 
#include <queue> 
#include <algorithm> 
using namespace std;
typedef pair<int, int> IP; 

IP dir[4] ={{0,1}, {1, 0}, {-1, 0}, {0, -1}}; 

IP operator+ (IP& a, IP& b){
  return {a.first + b.first, a.second + b.second}; 
}

queue<IP> here; 
int map[1005][1005]; 
bool visited[1005][1005]; 
int n, m; 

void print(){
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cout << map[i][j] << " "; 
    }
    cout << endl; 
  }
}


vector<IP> getPossible(IP cur){
  vector<IP> res; 
  queue<IP> tmp;
  res.push_back(cur); 
  map[cur.first][cur.second] = 3; 
  tmp.push(cur); 
  while(!tmp.empty()){
    cur = tmp.front();
    tmp.pop(); 
    for(int i = 0; i <4; i++){
      IP next = cur + dir[i]; 
      if(map[next.first][next.second] == 0){
        map[next.first][next.second] = 3; 
        tmp.push(next);
        res.push_back(next); 
      }
    }
  }
  return res; 
}

ostream& operator << (ostream& os, IP a){
  os << "(" << a.first << ", " << a.second << ")"; 
  return os; 
}


bool BFS(){
  for(int i = 0; i <= m+1; i++){
    for(int j = 0; j <= n+1; j++){
      visited[i][j] = false; 
    }
  }
  int size = here.size();
  IP cur, next;  
  cout << size << endl; 
  for(int i = 0; i < size; i++){
    cur = here.front(); 
    cout << "here is " << cur << endl; 
    cout << map[cur.first][cur.second] << endl; 
    here.pop(); 
    if(cur.first == m && cur.second == n)
      return true; 

    for(int k = 0; k < 4; k++){
      next = cur + dir[k]; 
      if(visited[next.first][next.second] == true)
        continue; 
      if(map[next.first][next.second] == 2){
        map[next.first][next.second] = 1;  
        visited[next.first][next.second] = true; 
        cout << next << "is melting..., so push" << cur << endl; 
        here.push(cur); 
      }
      else if(map[next.first][next.second] == 1){
        vector<IP> possible = getPossible(next); 
        for(int j = 0; j < possible.size(); j++){
          here.push(possible[j]); 
          cout << "find new way!, so push " << possible[j] << endl; 
        }
      }
    }
  }
  return false; 
}

int main(){
  cin >> m >> n; 
  for(int i = 0; i <= m; i++){
    map[i][0] = -1; 
    map[n+1][i] = -1; 
  }
  for(int i = 0; i <= n+1; i++){
    map[0][i] = -1; 
    map[m+1][i] = -1; 
  }
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cin >> map[i][j]; 
    }
  }

  vector<IP> more = getPossible({1, 1}); 
  print(); 
  for(int i = 0; i < more.size(); i++){
    here.push(more[i]); 
  }
  bool success = false; 
  int cost = 0; 
  while(!here.empty()){
    if(BFS()){
      success = true; 
      break; 
    }
    cout << "cost == " << cost << endl; 
    print(); 
    cost++; 
  }

  if(success == false)
    cout << -1 << endl; 
  else  
    cout << cost << endl; 
  return 0; 
}