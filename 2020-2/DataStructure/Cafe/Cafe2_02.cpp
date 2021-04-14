#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(auto i = j; i != k; i++)

int N, K, furthest;
typedef struct Seat {
  int ID;
  int nextDist; // Distance to next seat
  int seatNum;
} Seat;
typedef struct Poss {
  int seatNum;
  list<Seat>::iterator it;
} Poss;
list< Seat > seat;
vector < Poss > AS; // Available Seat
bool isExist[10001] = {0};

bool cmp1(Seat s1, Seat s2) { 
  return s1.nextDist < s2.nextDist;
}

bool cmp2(const Poss &p1, const Poss &p2) { 
  return p1.seatNum < p2.seatNum;
}

void removeSeat(int ID) { // Exit
  FOR (it, seat.begin(), seat.end()) {
    if (it->ID == ID) {
      int dist = it->nextDist; // Distance from the seat to be erased to the next seat
      it = seat.erase(it);
      if (it == seat.begin()) { // If erasing is the first seat
        auto tmp_it = seat.end();
        tmp_it--;
        tmp_it->nextDist += dist;
      } else {
        it--; // Check previous seat
        it->nextDist += dist; // Distance from previous seat to seat just erased + distance from seat just erased to next seat
      }
      break;
    }
  }
}

void findFurthest() {
  furthest = max_element(seat.begin(), seat.end(), cmp1) -> nextDist;
}

bool findMinSeat(int dist, int seatNum) {
  return (seatNum + dist/2 - 1) % N > (seatNum + dist/2 + dist%2 - 1) % N;
}

int findSeat(list<Seat>::iterator it, int ID) {
  int dist = it->nextDist; // Distance from current seat to next seat
  int seatNum = it->seatNum;
  if (findMinSeat(dist, seatNum)) { // Exception handling when two candidate seats are N and 1
    dist = dist/2 + dist%2; // dist%2 is to allocate fast seats in case of odd number.
  } else {
    dist = dist/2;
  }
  int newSeatNum = seatNum + dist;
  newSeatNum > N ? newSeatNum -= N : 0;
  return newSeatNum;
}

void setSeat(list<Seat>::iterator it, int newSeatNum, int ID)
{
  int dist = it->nextDist;
  int seatNum = it->seatNum;
  if (newSeatNum < seatNum) {
    int newDist = (newSeatNum + N)  - seatNum;
    it->nextDist = newDist;
    seat.push_front(Seat {ID, dist - newDist, newSeatNum});
  } else {
    int newDist = newSeatNum  - seatNum;
    it->nextDist = newDist;
    it++;
    seat.insert(it, Seat {ID, dist - newDist, newSeatNum});
  }
}

void printSeat(int ID, int seatNum)
{
  cout << ID << " " << seatNum << "\n";
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  FOR(k, 0, K) {
    int ID;
    cin >> ID;

    if (isExist[ID]) { // Exit if already sitting
      isExist[ID] = false;
      removeSeat(ID);
      findFurthest();
    } else { // Enter if not sitting
      if (furthest != 1) { // If have a seat
        isExist[ID] = true;
        if (seat.size() == 0) { // If all the seats are empty
          seat.push_back(Seat{ID, N, 1});
          furthest = N;
          printSeat(ID, 1);
        } else {
          FOR (it, seat.begin(), seat.end()) {
            if (it->nextDist == furthest) { // Find the furthest distance between seats
              AS.push_back( Poss {findSeat(it, ID), it} ); // Putting candidates
            }
          }
          Poss minAS = *min_element(AS.begin(), AS.end(), cmp2);
          setSeat(minAS.it, minAS.seatNum, ID);
          printSeat(ID, minAS.seatNum);
          AS.clear();
          findFurthest();
        }
      }
    }
  }
}