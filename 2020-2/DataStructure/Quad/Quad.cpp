#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)


string type, qts;
char img[64][64];
int K, imgSize, q = 0;
typedef struct {
  int x;
  int y;
} Point;

void input()
{
  cin >> K;
  cin >> type;

  FOR(i, pow(2, K)) {
    FOR (j, pow(2, K)) {
      img[i][j] = '0';
    }
  }
  imgSize = pow(2, K);
  if (type == "QTS") {
    cin >> qts;
  } else if (type == "IMG") {
    FOR(i, imgSize) {
      FOR(j, imgSize) {
        cin >> img[i][j];
      }
    }
  }
}

Point movePoint(int bracket, int quad, Point p)
{
  switch (quad) {
  case 0:
    p.x += pow(2, K - bracket); 
    break;
  case 1:
    break;
  case 2:
    p.y += pow(2, K - bracket);
    break;
  case 3:
    p.x += pow(2, K - bracket);
    p.y += pow(2, K - bracket);
    break;
  default:
    break;
  }
  return p;
}

void draw(int bracket, int quad, char pixel, Point p)
{
  Point copyP = p;
  if (bracket == K + 1) {
    img[p.y][p.x] = pixel;
    return;
  }
  FOR(quad, 4) {
    p = copyP;
    p = movePoint(bracket, quad, p);
    if (qts[q] == '(') {
      q++;
      draw(bracket + 1, quad, ' ', p);
      q++;
    } else {
      if (pixel == ' ') {
        pixel = qts[q];
        draw(bracket + 1, quad, pixel, p);
        pixel = ' ';
        q++;
      } else {
        draw(bracket + 1, quad, pixel, p);
      }
    }
  }
  return;
}

char cmprs(int bracket, int quad, Point p)
{
  bool state = true;
  Point copyP = p;
  if (bracket == K + 1) {
    return img[p.y][p.x];
  }
  qts += '(';
  FOR(quad, 4) {
    p = copyP;
    p = movePoint(bracket, quad, p);
    char pixel = cmprs(bracket + 1, quad , p);
    if (pixel != ' ') {
      qts += pixel;
    }
  }
  char s = qts[qts.length() - 1];
  FOR(i, 3) {
    if (s != qts[qts.length() - i - 2]) {
      state = false;
    }
  }
  if (state) {
    qts.erase(qts.length() - 5);
    return s;
  } else {
    qts += ')';
    return ' ';
  }
}

void solve()
{
  int bracket = 0, quad = 0;
  char pixel = 0;
  Point p = {0, 0};
  if (type == "QTS") {
    q = 0;
    if (qts[q] == '(') {
      q++;
      draw(bracket + 1, quad, ' ', p);
      q++;
    } else {
      pixel = qts[q];
      draw(bracket + 1, quad, pixel, p);
      q++;
    }
  } else if (type == "IMG") {
    pixel = cmprs(bracket + 1, quad, p);
    if (pixel != ' ') {
      qts += pixel;
    }
  }
}

void print()
{
  if (type == "QTS") {
    FOR(i, pow(2, K)) {
      FOR (j, pow(2, K)) {
        cout << img[i][j];
      }
    cout << "\n";
  }
  } else if (type == "IMG") {
    cout << qts << "\n";
  }
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