#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N;
int least[4] = {0};
priority_queue<int, vector<int>, greater<int> > ans;
int ansPrice = INF;
int ansTotal;
class D {
  public:
    int price;
    int index;
    int cal[4];
    
    D() {
      this->price = 0;
      this->index = 0;
    }

    void setD (int price, int index, int d1, int d2, int d3, int d4){
      this->price = price;
      this->index = index;
      this->cal[0] = d1;
      this->cal[1] = d2;
      this->cal[2] = d3;
      this->cal[3] = d4;
    }

    bool operator <(D &d){
      if (this->price != d.price) {
        return this->price < d.price;
      } else {
        return this->index < d.index;
      }
    } 
};
D* d = new D[51];

void input()
{
  ifstream in("food.inp");
  in >> N;
  FOR(i, 4) {
    in >> least[i];
  }
  FOR(n, N) {
    int price, tmp[4];
    FOR(i, 4) {
      in >> tmp[i];
    }
    in >> price;
    d[n].setD(price, n + 1, tmp[0], tmp[1], tmp[2], tmp[3]);
  }
  sort(&d[0], &d[N]);
  in.close();
}

void DFS(int n, int currCal[4], vector<int> choice, int currPrice)
{
  bool flag = true;
  FOR(i, 4) {
    if (least[i] > currCal[i]) {
      flag = false;
      break;
    }
  }

  if (flag) {
    if (ansPrice > currPrice) {
      ansPrice = currPrice;
      priority_queue<int, vector<int>, greater<int> > tmp;
      FOR(i, choice.size()) {
        tmp.push(choice[i]);
        // cout << choice[i] << ' ';
      }
      // cout << '\n';
      ans = tmp;
      int currTotal = 0;
      FOR(i, 4) {
        currTotal += currCal[i];
      }
      ansTotal = currTotal;
    } else if (ansPrice == currPrice) {
      int currTotal = 0;
      FOR(i, 4) {
        currTotal += currCal[i];
      }
      if (ansTotal < currTotal) {
        priority_queue<int, vector<int>, greater<int> > tmp;
        FOR(i, choice.size()) {
          tmp.push(choice[i]);
        }
        ans = tmp;
        ansTotal = currTotal;
      } else if (ansTotal == currTotal) {
        sort(choice.begin(), choice.end());
        vector<int> tmp;
        while(!ans.empty()) {
          tmp.push_back(ans.top());
          ans.pop();
        }
        if (choice < tmp) {
          FOR(i, choice.size()) ans.push(choice[i]);
        } else {
          FOR(i, tmp.size()) ans.push(tmp[i]);
        }
      }
    }
    return;
  }

  for(int next_n = n + 1; next_n < N; next_n++) {
    FOR(i, 4) {
      currCal[i] += d[next_n].cal[i];
    }
    choice.push_back(d[next_n].index);
    DFS(next_n, currCal, choice, currPrice + d[next_n].price);
    choice.pop_back();
    FOR(i, 4) {
      currCal[i] -= d[next_n].cal[i];
    }
  }
}

void solve()
{
  FOR(n, N) {
    vector<int> choice;
    int currCal[4];
    FOR(i, 4) {
      currCal[i] = d[n].cal[i];
    }
    choice.push_back(d[n].index);
    DFS(n, currCal, choice, d[n].price);
  }
}

void print()
{
  // cout << ansTotal << '\n';
  // while(!ans.empty()) {
  //   cout << ans.top() << ' ';
  //   ans.pop();
  // }
  ofstream out("food.out");
  while(!ans.empty()) {
    out << ans.top() << ' ';
    ans.pop();
  }
  out.close();
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