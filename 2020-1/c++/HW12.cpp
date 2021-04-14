#include <iostream>

using namespace std;

class StackException
{
  const string msg;

public:
  StackException(const string& _msg) : msg(_msg) {};
  void print() const { cout << msg << endl; }
};

class CharStack
{
  int size;
  int top;
  char *s;

public:
  CharStack(int sz)
  {
    try {
      if (sz < 0) throw StackException("ERROR : bad alloc");
      top = 0;
      s = new char[size = sz];
    } catch (const StackException& se) {
      se.print();
    }
  }
  // destructor, copy constructor, and assignment operator
  void push(char c)
  { 
    try {
      if (top == size) throw StackException("ERROR : max size");
      s[top++] = c;
    } catch (const StackException& se) {
      se.print();
    }
  }
  char pop()
  {
    try {
      if (top == 0) throw StackException("ERROR : can't pop anymore");
      char r = s[--top];
      s[top] = '\0';
      return r;
    } catch (const StackException& se) {
      se.print();
    }
  }
  void print() const
  {
    for (int i = 0; i < top; i++)
      cout << s[i];
    cout << endl;
  }
};

int main()
{
  CharStack cs(1);
  cs.push('A');
  cs.print();
  cs.push('B');
  cs.print();
  cs.pop();
  cs.print();
  cs.pop();
  cs.print();
  cs.pop();
  cs.print();
  cs.push('B');
  cs.print();
}