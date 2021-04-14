#include <iostream>
#include <vector>

using namespace std;

string str;
vector<int> I, N;

void input()
{
  cin >> str;
}

void solve()
{
  int answer = 0;
  int m = str.length();
  int j = 0;
  vector<int> pi(m);
  for (int i = 1; i < m; i++) {
    if (j == 0 && str[i] == str[j]) { // 같은게 생겼다? -> 합리적의심 시작
      answer = i;
    }
    while (j != 0 && str[i] != str[j]) { // str[i] == str[j]가 될 때 까지 pi를 이용해 되돌아가기
      j = pi[j-1];
      answer = i - j;
    }
    if (str[i] == str[j]) {
      pi[i] = ++j;
    }
    if (j == 0) { // 같은게 없어졌다? -> 반복 안하는중
      answer = 0;
    }

    if (answer != 0) { // answer가 0이 아니라는 건 합리적 의심중이라는 뜻
      if (pi[i] % answer == 0) { // answer 크기만큼 pi가 증가중이다 -> 반복중
        I.push_back(i+1);
        N.push_back(pi[i] / answer + 1);
      }
    }
  }
}

void print()
{
  for (int i = 0; i < I.size(); i++) {
    cout << I[i] << " " << N[i] << "\n";
  }
}

int main()
{
  input();
  solve();
  print();
}

/*
예시입니다
str
pi

abababababab
0012345678910

aaaaaa
012345

ababcababc
0012012345

aab aab aab aab
010 123 456 789

aaba aaba
0101 2234
*/