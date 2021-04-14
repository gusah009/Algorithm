#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Rectangle {
  int width ;
  int height ;
};
enum CommandKind {ADD, SORT, PRINT, CLEAR, EXIT, INVALID};

CommandKind getCommandKind(string commandString) {
  string Command[6] = {"ADD", "SORT", "PRINT", "CLEAR", "EXIT", "INVALID"};
  for(int i = 0; i < 6; i++) {
    if(commandString == Command[i]) {
      return static_cast<CommandKind>(i);
    }
  }
  return INVALID;
}

Rectangle getRectangle() {
  Rectangle input;
  cin >> input.width >> input.height;
  return input;
}

void print(vector<Rectangle> rectangles) {
  cout << "Rectangle Count: " << rectangles.size();
  const vector<Rectangle>::iterator iter = rectangles.begin();
  for(int i = 0; i < rectangles.size(); i++) {
    cout << "\t" << iter[i].width << " "<< iter[i].height << iter[i].width*iter[i].height;
  }
}

void sort(vector<Rectangle> &rectangles) {
  sort(rectangles.begin(), rectangles.end());
}

int main()
{
  vector<Rectangle> rectangles;
  while (true)
  {
    string commandString;
    cin >> commandString;
    const CommandKind command = getCommandKind(commandString);
    switch (command)
    {
      case ADD:
      {
        const Rectangle& newRectangle = getRectangle();
        rectangles.push_back(newRectangle);
        break;
      }
      case PRINT:
        print(rectangles);
        // use const_iterator in print()
        // define and call print(const Rectangle&)
        break;
      case SORT:
      {
        sort(rectangles); // define and call swap in sort()
        print(rectangles);
        break;
      }
      case CLEAR:
        rectangles.clear();
        break;
      case EXIT:
        break;
      default:
        assert(false);
        break;
    }
    if (command == EXIT)
      break;
  }
}