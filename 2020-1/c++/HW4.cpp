#include <iostream>
#include <vector>

using namespace std;

class Student {
  private:
    string name;
    float gpa;
  public:
    Student(string name, float gpa) {
      this->name = name;
      this->gpa = gpa;
    }
    void setGPA(float gp) {
      gpa = gp;
    }
    void setName(string nm) {
      name = nm;
    }
    float getGpa() {
      return gpa;
    }
    string getName() {
      return name;
    }
};

class School {
  private:
    string schoolName;
    vector<Student> students;
  public:
    School(string sn) {
      schoolName = sn;
    }
    void addStudent(string n1, float s1) {
      students.push_back(Student(n1, s1));
    }
    void addStudent(string n1) {
      students.push_back(Student(n1, 0.0));
    }
    void print() {
      cout <<"School Name: " << schoolName << ", Count: " << students.size() << "\n";
      for(int i = 0; i < students.size(); i++) {
        cout << "\tName: " << students[i].getName() << " GPA: " << students[i].getGpa() << "\n";
      }
      cout << "\n";
    }
    void sort() {
      for(int i = 0; i < students.size(); i++) {
        for(int j = i; j < students.size(); j++) {
          if(students[i].getGpa() < students[j].getGpa()) {
            Student stmp = students[i];
            students[i] = students[j];
            students[j] = stmp;
          }
        }
      }
    }
    Student& findStudentWithName(string n2) {
      for(int i = 0; i < students.size(); i++) {
        if(students[i].getName() == n2) {
          return students[i];
        }
      }
    }
};

int main()
{
  School pnu("PNU");
  pnu.addStudent("Kim", 2.7F);
  pnu.addStudent("Hong", 3.5F);
  pnu.addStudent("Lee");
  pnu.addStudent("Joo", 1.5F);
  pnu.print();
  pnu.sort(); // descending
  pnu.print();
  School knu("KNU");
  knu.addStudent("Seo", 2.5F);
  knu.addStudent("Lee", 3.8F);
  knu.print();
  Student &lee = pnu.findStudentWithName("Lee");
  lee.setGPA(3.3F);
  lee.setName("Yoon");
  pnu.print();
  knu.addStudent("Hong", 4.3F);
  Student &hong = knu.findStudentWithName("Hong");
  hong.setGPA(3.3F);
  hong.setName("Joon");
  knu.print();
}