#include <iostream>

using namespace std;

class MyString {
  char* str;
  int size;
public:
  MyString() {

  }
  MyString(char* lang) {
    str = lang;
    for(size = 0; lang[size] != '\0'; size++) {}
  }
  MyString(const MyString& ms) {
    str = ms.str;
    for(size = 0; ms.str[size] != '\0'; size++) {}
  }
  void set(char* lang) {
    str = lang;
    for(size = 0; lang[size] != '\0'; size++) {}
  }
  bool isEqual(const MyString& ms) const {
    if(size != ms.size) {
      return false;
    }
    for(int i = 0; i < size; i++) {
      if(str[i] != ms.str[i]) {
        return false;
      }
    }
    return true;
  }
  void print() const {
    cout << str << "\n";
  }
};

int main()
{
  MyString strs[] = {
      MyString("C"),
      MyString(),
      MyString("Java")};
  strs[1].set("C++");
  const MyString target("Java");
  for (int i = 0; i < 3; i++)
  {
    const MyString str(strs[i]);
    if (str.isEqual(target))
    {
      cout << "[" << i << "]: ";
      str.print();
      break;
    }
  }
  for (int i = 0; i < 3; i++)
  {
    const MyString &str = strs[i];
    str.print();
  }
}
