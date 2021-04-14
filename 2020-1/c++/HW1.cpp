#include <iostream>
#include <string>

using namespace std;

int Command(string com) {
  for (int i = 0; i < com.size(); i++) {
    com[i] = tolower(com[i]);
  }

  string comArr[4] = {"add", "sum", "average", "quit"};

  for(int i = 0; i < 4; i++) {
    if(com == comArr[i]) {
      return i;
    }
  }
  return -1;
}

int main() {
  int maxSize;
  int count = 0;
  string com;
  cout << "Enter the score count: ";
  cin >> maxSize;

  int* const scores = new int[maxSize];

  do  {
    cout << "Enter command: (add, sum, average, quit)";
    cin >> com;
    switch(Command(com)) {
      case 0:
        int score;
        cout << "Enter score: ";
        cin >> score;
        if(score > 100 || score < 0) {
            cout << "Score should be between 0 and 100" << endl;
        }
        else {
          if(count < maxSize) {
            scores[count] = score;
            count++;
            cout << "    " << score << " added" << endl;
          }
          else {
            cout << "Too many scores" << endl;
          }
        }
      break;
      case 1: {
        int sum = 0;
        for(int i = 0; i < count; i++) {
          sum += scores[i];
        }
        cout << "    " << "Sum: " << sum << endl;
      break;
      }
      case 2: {
        float avg = 0;
        for(int i = 0; i < count; i++) {
          avg += scores[i];
        }
        avg /= count;
        cout << "    " << "Average: " << avg << endl;
      break;
      }
      case 3: {
        cout << "    " << "Bye" << endl;
      break;
      }
      case -1: {
        cout << "    " << "Wrong Input please again" << endl;
      break;
      }
    }
  } while(Command(com) != 3);
  delete [] scores;
}
