#include <iostream>
#include "queue.h"

int main(void) {
  Queue<string> *myQueue = new Queue<string>(100);
  myQueue->enqueue("Alex");
  myQueue->enqueue("Doug");
  myQueue->enqueue("Finance");
  try {
    cout << "REMOVED: " << myQueue->dequeue() << endl;
  } catch (const char* msg) {
    cout << msg << endl;
  }
  cout << "\n" << endl;
  cout << "CONTAINS ALEX: " << myQueue->contains("Alex") << endl;
  cout << "CONTAINS DOUG: " << myQueue->contains("Doug") << endl;
  cout << "CONTAINS FINANCE: " << myQueue->contains("Finance") << endl;
  cout << "FRONT IS: " << myQueue->get_front() << endl;
  cout << "IS EMPTY?: " << myQueue->is_empty() << endl;

  try {
    cout << "REMOVED: " << myQueue->dequeue() << endl;
  } catch (const char* msg) {
    cout << msg << endl;
  }

  cout << "CONTAINS DOUG: " << myQueue->contains("Doug") << endl;
  cout << "CONTAINS FINANCE: " << myQueue->contains("Finance") << endl;

  try {
    cout << "REMOVED: " << myQueue->dequeue() << endl;
  } catch (const char* msg) {
    cout << msg << endl;
  }

  try {
    cout << "REMOVED: " << myQueue->dequeue() << endl;
  } catch (const char* msg) {
    cout << msg << endl;
  }

  myQueue->~Queue();

  return 0;
}
