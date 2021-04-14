#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define FRIENDS 3
#define VERTEX 26

int N, start[FRIENDS], ansTime;
char ansLocation = 'z' + 1;
bool isPoss[FRIENDS][VERTEX];
vector<int> vertex[VERTEX];

void input()
{
   FOR(i, FRIENDS)
      FOR(j, VERTEX)
         isPoss[i][j] = false;

   cin >> N;
   FOR(i, FRIENDS) {
      char tmp;
      cin >> tmp;
      start[i] = tmp - 'a';
      isPoss[i][start[i]] = true;
   }
   char s;
   FOR(n, N) {
      cin >> s;
      char v = NULL;
      cin >> v;
      while (v != '$') {
         int next = int(v - 'a');
         vertex[s - 'a'].push_back(next);
         cin >> v;
      }
   }
}

void solve(priority_queue<int> pq[FRIENDS], int depth)
{
   priority_queue<int> pq2[FRIENDS];
   FOR(f, FRIENDS) {
      while (!pq[f].empty()) {
         int v = -pq[f].top();
         isPoss[f][v] = true;
         FOR(i, vertex[v].size()) {
            int next = vertex[v][i];
            if (isPoss[f][next] == false) {
               pq2[f].push(-next);
            }
         }
         pq[f].pop();
      }
   }
   
   bool state;
   FOR(v, VERTEX) {
      state = true;
      FOR(f, FRIENDS) {
         if (isPoss[f][v] == false) state = false;
      }
      if (state) {
         if (char(v + 'a') < ansLocation) {
            ansLocation = char(v + 'a');
            ansTime = depth * 3 - 2;
         }
         return;
      }
   }
   solve(pq2, depth + 1);
}

void print()
{
   cout << ansLocation << "\n";

   if (ansTime < 0)  cout << "0\n";
   else              cout << ansTime << "\n";
}

int main()
{
   input();
   priority_queue<int> pq[FRIENDS];
   FOR(f, FRIENDS) pq[f].push(-start[f]);
   solve(pq, 0);
   print();

   return 0;
}