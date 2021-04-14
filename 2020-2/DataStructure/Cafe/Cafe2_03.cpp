#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(auto i = j; i != k; i++)

typedef struct Seat {
  int ID;
  int prev; // prevSeatNum
  int next; // nextSeatNum
} Seat;
array<Seat, 1000001> seat;
priority_queue<int, vector<int>, less<int>> distSet;
priority_queue<int, vector<int>, less<int>> removeSet;
int N, K, seatNum;
vector<Seat> AS; // Available Seat
int isExist[10001] = {0};

void removeSeat(int ID) {
  int num = isExist[ID];
  if (seat[0].next == num) {
    seat[0].next = seat[seat[0].next].next;
  }
  removeSet.push((num - seat[num].prev + N) % N);
  removeSet.push((seat[num].next - num + N) % N);
  seat[seat[num].prev].next = seat[num].next;
  seat[seat[num].next].prev = seat[num].prev;
  distSet.push((seat[num].next - seat[num].prev + N) % N);
  isExist[ID] = 0;
}

void setSeat(Seat newSeat, int ID) {
  int pS = newSeat.prev; // prevSeat 번호
  int nS = newSeat.next; // newSeat 번호
  seat[nS].ID = ID;
  seat[nS].next = seat[pS].next;
  seat[seat[nS].next].prev = nS;
  seat[pS].next = nS;
  seat[nS].prev = pS;
  distSet.pop();
  distSet.push((seat[nS].next - nS + N) % N);
  distSet.push((nS - seat[nS].prev + N) % N);
}

void findFurthest() {
  while(distSet.top() == removeSet.top()) {
    distSet.pop();
    removeSet.pop();
  }
}

bool findMinSeat(int dist, int num) {
  return (num + dist/2 - 1) % N > (num + dist/2 + dist%2 - 1) % N;
}

Seat findSeat(int num, int ID) {
  int dist = distSet.top();
  if (dist <= 0) dist += N;
  if (findMinSeat(dist, num)) { // Exception handling when two candidate seats are N and 1
    dist = dist/2 + dist%2; // dist%2 is to allocate fast seats in case of odd number.
  } else {
    dist = dist/2;
  }
  int newSeat = num + dist;
  newSeat > N ? newSeat -= N : 0;
  return Seat{ID, num, newSeat};

}
void printSeat(int ID, int num) {
  cout << ID << " " << num << "\n";
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  seat[0] = Seat{0,0,0};
  distSet.push(-1);
  removeSet.push(-2);

  FOR(k, 0, K) {
    int ID;
    cin >> ID;
    
    findFurthest();
    if(isExist[ID] != 0) {
      removeSeat(ID);
    } else {
      if (distSet.top() != 1) {
        if (distSet.size() == 1) {
          isExist[ID] = 1;
          seat[1] = Seat{ID, 1, 1};
          seat[0].next = 1;
          distSet.push(N);
          seatNum = 1;
          printSeat(ID, 1);
        } else {
          int first = seat[0].next;
          int last = seat[first].prev;
          if (first - last + N == distSet.top()) {
            Seat fS = findSeat(last, ID);
            if (fS.next <= first) {
              AS.push_back(findSeat(last, ID));
            }
          }
          if (AS.size() == 0) {
            for (int num = first; num != last;) {
              if(seat[num].next - num == distSet.top()) {
                AS.push_back(findSeat(num, ID));
                break;
              }
              num = seat[num].next;
            }
            AS.push_back(findSeat(last, ID));
          }
          setSeat(AS[0], ID);
          isExist[ID] = AS[0].next;
          printSeat(ID, AS[0].next);
          AS.clear();
        }
      }
    }
  }
}