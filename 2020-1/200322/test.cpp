#include <iostream>
using namespace std;
#include <stdlib.h>

int* sum = new int;

class Queue {
private:
   int line[20];
   static int number;
   
public:
   Queue();
   void Push();
   void Pop();
   static int Number();
   friend ostream& operator<< (ostream& os, const Queue& L) {

      for (int i = 0; i < 20; i++)
         cout << "  " << L.line[i];
      cout << endl;
      return os;
   }
   int add();
   void initadd();

};
void Queue::initadd() {
   *sum = 0;
}

int Queue::add() {
   for (int i = 0; i < 20; i++) {
      *sum += line[i];
   }
   return *sum;
}
Queue::Queue() {
   number = 0;
}
void Queue::Push() {
   for (int i = 0; i < 20; i++) {
      cin >> line[number];
      number++;
      cout << number << endl;
      cout << line[number-1] << " has joined the queue" << endl;
   }
}

void Queue::Pop() {
   for (int i = 1; i < number; i++)
      line[i - 1] = line[i];
   number--;

   cout << line[number] << " has left the queue" << endl;
}
int Queue::Number() {
   return number;
}
int Queue::number = 0;

int main() {
   Queue q;
   Queue t;
   int qsum =0;
   int tsum =0;
   while (1)
   {
      int select;
      //testing plan: A) run 1. and 3, B) run 2 and 3
      cout << "\nSelect command 1: Input Queue q 20 numbers, 2: Input Queue t 20 numbers, 3. display q & t, 4.add q & t, 5. Quit => ";
      cin >> select;
      switch (select) {
      case 1:
         q.Push();
         break;

      case 2:
         t.Push();
         break;

      case 3:      
         cout << q;
         cout << t;

         break;
      case 4:
         q.initadd();
         qsum = q.add();
         cout << "sum of elements of Queue q : " << qsum << endl;
         cout << "static number : " << q.Number() << endl;
         q.Number();
                   
         t.initadd();
         tsum = t.add();
         cout << "sum of elements of Queue t : " << tsum << endl;
         cout << "static number : " << t.Number() << endl;
         t.Number();
         break;
      default:
         exit(0);
         break;
      }
   }

   system("pause");
}