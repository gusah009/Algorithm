#include <iostream>
#include <vector>

using namespace std;

enum EmployeeLevel {사원,  대리,  과장,  차장,  부장};

class Employee
{
  protected:
    string name;
    const EmployeeLevel level;

  public:
    Employee (string _name, EmployeeLevel lv) : level(lv){
      name = _name;
    }
    string getName() {
      return name;
    }
    EmployeeLevel getLevel() {
      return level;
    }
    friend ostream& operator << (ostream& os, const Employee& e);
};

ostream& operator << (ostream& os, const Employee& e) {
  os << e.level << "\t" << e.name << "\n" ;
  return os ;
}

class Manager : public Employee
{
  protected:
    vector<Employee *> group;

  public:
    Manager(string _name, EmployeeLevel lv) : Employee(_name, lv) {}
    void addEmployee(Employee* e) {
      group.push_back(e);
    }

    friend ostream& operator << (ostream& os, const Manager& m);
};

ostream& operator << (ostream& os, const Manager& m) {
  os << m.name << "\t" << m.level << "\n" ;
  os << "List of employees managed by me\n";
  for (int i = 0; i < m.group.size(); i++) {
    os << (*(m.group[i])).getLevel() << "\t" << (*(m.group[i])).getName() << "\n";
  }
  return os ;
}

int main()
{
  Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원);
  cout << e1 << e2 << e3 ;
  Manager m1("Tom", 차장) ;
  m1.addEmployee(&e1) ;
  m1.addEmployee(&e2) ;
  m1.addEmployee(&e3) ;
  cout << endl << "Information for Manager" << endl ;
  cout << m1 ;
}
