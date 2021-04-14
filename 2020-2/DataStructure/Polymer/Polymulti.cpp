#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(auto i = j; i != k; i++)

typedef struct {
  long long int coe; // 계수
  long long int ind; // 지수
} Term;

long long int N, M, c, e, counting;
vector<Term> prev_polymer;
vector<Term> curr_polymer;
long long int polymer[10001] = {0}; // polymer[지수] = 계수;

void print()
{
  if (prev_polymer.size() == 0) {
    cout << "1" << "\n" << "0 0" << "\n";
  } else {
    cout << prev_polymer.size() << "\n";
    FOR(it, prev_polymer.begin(), prev_polymer.end()) {
      cout << it->coe << " "  << it->ind << "\n";
    }
  }
}


void inputAndSolve()
{
  cin >> N;
  if (N == 0) {
    prev_polymer.clear();
    return;
  } else {
    FOR(n, 0, N) {
      cin >> M;

      curr_polymer.clear();

      FOR(m, 0, M) {
        cin >> c >> e;
        curr_polymer.push_back(Term{c,e});
      }

      // cout << "n: " << n << "\n";

      FOR(itCurr, curr_polymer.begin(), curr_polymer.end()) {
        FOR(itPrev, prev_polymer.begin(), prev_polymer.end()) {
          polymer[itPrev->ind + itCurr->ind] += itPrev->coe * itCurr->coe;
          // cout << "it: " << itPrev->ind + itCurr->ind << " " << itPrev->coe * itCurr->coe << "\n";
        }
      }
      
      prev_polymer.clear();

      for(int i = 10000; i >= 0; i--) {
        if (polymer[i] != 0) {
          prev_polymer.push_back(Term{polymer[i], i});
          // cout << "prev: " << polymer[i] << " " << i << "\n";
        }
        polymer[i] = 0;
      }
      // cout << "\n";
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  prev_polymer.push_back(Term{1,0});
  inputAndSolve();
  print();
}