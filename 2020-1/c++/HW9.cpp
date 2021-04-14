#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

enum Color {RED, BLUE, YELLOW} ;

class Point
{
  int x, y;

public:
  Point() {}
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
  int get_x() const {
    return x;
  }
  int get_y() const {
    return y;
  }
};

class Shape
{
  Color lineColor ;
public:
  Color getLineColor() const { return lineColor ; }
  virtual Shape* clone() const = 0 ;
  virtual void print() const = 0 ;
  virtual float getLength() const = 0 ;
};

class ClosedShape : public Shape
{

};

class Polygon : public ClosedShape
{

};

class Triangle : public Polygon
{
  Point p[3];
  char S = 'T';
public:
  Triangle(const Point* point) {
    p[0] = point[0];
    p[1] = point[1];
    p[2] = point[2];
  }
  Triangle(Point p1, Point p2, Point p3) {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
  }
  virtual void print() const {
    cout << "Triangle: ";
    for (int i = 0; i < 3; i++) {
      cout << "(" << p[i].get_x() << ", " << p[i].get_y() << ")";
    }
    cout << endl;
  }
  virtual float getLength() const {
    return float(abs((p[1].get_x() - p[0].get_x()) * (p[2].get_y() - p[0].get_y()) - (p[2].get_x() - p[0].get_x()) * (p[1].get_y() - p[0].get_y())))/2;
  }
  virtual Shape* clone() const {
    Shape* T = new Triangle(p);
    return T;
  }
};

class Rectangle : public Polygon
{
  Point p[4];
  char S = 'R';
public:
  Rectangle(const Point* point) {
    p[0] = point[0];
    p[1] = point[1];
    p[2] = point[2];
    p[3] = point[3];
  }
  Rectangle(Point p1, Point p2, Point p3, Point p4) {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
  }
  virtual void print() const {
    cout << "Rectangle: ";
    for (int i = 0; i < 4; i++) {
      cout << "(" << p[i].get_x() << ", " << p[i].get_y() << ")";
    }
    cout << endl;
  }
  virtual float getLength() const {
    Triangle T1(p[0], p[1], p[2]);
    Triangle T2(p[1], p[2], p[3]);
    return T1.getLength() + T2.getLength();
  }

  virtual Shape* clone() const {
    Shape* R = new Rectangle(p);
    return R;
  }
};

class ShapeList
{
  vector<Shape*> list;

public:
  void addShape(Shape* s) {
    list.push_back(s->clone());
  }

  void print() const {
    for(int i = 0; i < list.size(); i++) {
      (*(list[i])).print();
    }
  }
  float getTotalArea() {
    float sum = 0;
    for(int i = 0; i < list.size(); i++) {
      sum += (*(list[i])).getLength();
    }
    return sum;
  }
};

int main()
{
  Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);
  Shape *const r = new Rectangle(p1, p2, p3, p4);
  Shape *const t = new Triangle(p1, p2, p3);
  ShapeList list{};
  list.addShape(r);
  list.addShape(t);
  delete r;
  delete t;
  list.print();
  cout << list.getTotalArea() << endl;
}