#include <iostream>

using namespace std;

class MyString
{
private:
  char *str;

public:
  MyString() {}
  MyString(char* _str) : str(_str) {}
  bool operator==(const MyString other) const {
    if(str == other.str) {
      return true;
    }
    else {
      return false;
    }
  }
  void print() const {
    cout << str;
  }
};

class Complex
{
private:
  float real, imaginary;
public:
  Complex() {}
  Complex(float _real, float _imaginary) : real(_real), imaginary(_imaginary) {}
  bool operator==(const Complex other) const {
    if((real == other.real) && (imaginary == other.imaginary)) {
      return true;
    }
    else {
      return false;
    }
  }
  void print() const {
    cout << real << "," << imaginary;
  }
};

template <class T, int size>
class List {
  private:
    T data_type[size];
    int len;
  public:
    List(int _len = 0) : len(_len) {}
    List(const List<T, size> &l, int _len = 0) : len(_len) {
      for (int i = 0; i < l.len; i++) {
        data_type[i] = l.data_type[i];
      }
      len = l.len;
    }
    void add(const T data) {
      data_type[len] = data;
      len++;
      data.print();
      cout << " is added" << "\n";
    }
    void find(const T data) {
      int i;
      bool state = false;
      for (i = 0; i < len; i++) {
        if(data_type[i] == data) {
          data.print();
          cout << " is found" << "\n";
          state = true;
          break;
        }
      }
      if (!state) {
        data.print();
        cout << " is not found" << "\n";
      }
    }
    void remove(const T data) {
      int i;
      bool state = false;
      for (i = 0; i < len; i++) {
        if(data_type[i] == data) {
          for (int j = i; j < len - 1; j++) {
            data_type[j] = data_type[j + 1];
          }
          len--;
          state = true;
          data.print();
          cout << " is removed" << "\n";
          break;
        }
      }
      if (!state) {
        data.print();
        cout << " is not removed" << "\n";
      }
    }
    void print() {
      for (int i = 0; i < len; i++) {
        data_type[i].print();
        cout << "\n";
      }
    }
};

int main()
{
  List<Complex, 100> cList;
  List<MyString, 200> sList;
  cList.add(Complex(0, 0));
  cList.add(Complex(1, 1));
  sList.add("abc");
  sList.add("def");
  cList.find(Complex(1, 0));
  sList.find("def");
  cList.remove(Complex(0, 0));
  sList.remove("abc");
  List<MyString, 200> s2List(sList);
  List<MyString, 200> s3List;
  s3List.add("123");
  s3List = s2List;
  s3List.remove("def");
}
