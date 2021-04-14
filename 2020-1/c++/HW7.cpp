// #include <iostream>

// using namespace std;

// class Matrix
// {
//   int **values;
//   int row, column;

// public:
//   friend ostream& operator << (ostream& os, Matrix& m) ;
//   friend istream& operator >> (istream& is, Matrix& m);
// };

// ostream &operator<<(ostream &os, Matrix& m)
// {
//   os << m.re << " + " << m.im << "i";
//   return os;
// }
// istream &operator>>(istream &is, Matrix& m)
// {
//   is >> m.re >> m.im;
//   return is;
// }

// int main()
// {
//   Matrix m1(2, 2), m2(2, 2);
//   cin >> m1;
//   cin >> m2;
//   Matrix m3(m1 + m2);
//   Matrix m4(2, 2);
//   m4 = m3 * 10;
//   cout << m3 << endl << m4 << endl;
// }
