#include <vector>
#include <iostream>

using namespace std;

const int SUBJECT_NO = 3;
struct StudentInfo {
  string name;
  int scores[SUBJECT_NO];
  int sum;
  float average;
};

int main() {
  vector<StudentInfo> students(0); 
  StudentInfo input;
  StudentInfo total;
  int num;
  int i = 0;
  total.scores[0] = 0;
  total.scores[1] = 0;
  total.scores[2] = 0;
  total.sum = 0;
  
  cin >> num;
  for(int n = 0; n < num; n++) {
    cin >> input.name >> input.scores[0] >> input.scores[1] >> input.scores[2];
    input.sum = input.scores[0] + input.scores[1] + input.scores[2];
    input.average = input.sum/3.0;
    students.push_back(input);
    total.scores[0] += input.scores[0];
    total.scores[1] += input.scores[1];
    total.scores[2] += input.scores[2];
    total.sum += input.sum;
  }

  
  for(vector<StudentInfo>::iterator iter = students.begin(); iter != students.end(); iter++, i++) {
    cout << i+1 <<  "\t" << iter[0].name << "\t" << iter[0].scores[0] << "\t" << iter[0].scores[1] << "\t" << iter[0].scores[2] << "\t" << iter[0].sum << "\t" << iter[0].average << "\n";
  }
  cout << "total" << "\t" << total.name << "\t" << total.scores[0] << "\t" << total.scores[1] << "\t" << total.scores[2] << "\t" << total.sum << "\n";
}