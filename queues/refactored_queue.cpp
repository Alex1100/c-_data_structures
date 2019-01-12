#include <iostream>

using namespace std;


/**************************************
 * @class Queue
 * @desc  Implements Queue
 *************************************/
template <class T>
class Queue{
private:
  int front, rear, max;
  T *q;
public:
  Queue(int size=0){
    front = rear = 0;
    max = size;
    q = new T[size];
  }
  ~Queue(){
    delete []q;
  }
  T get_front();
  T dequeue();
  T get_item_at(int index);
  void print_queue();
  void enqueue(T);
  bool contains(T item);
  bool is_empty();
};


template <class T>
void Queue<T>::enqueue(T elem){
  if(front >= max){
    throw "Out of space. Reallocate memory";
  }
  q[rear] = elem; rear++;
}

template <class T>
T Queue<T>::dequeue(){
  if(this->is_empty()){
    throw "Empty Queue";
  }

  T result = q[front];
  for (int i = 0; i < rear; i++) {
    swap(q[i], q[i + 1]);
  }

  --rear;
  return result;

}

template <class T>
void Queue<T>::print_queue(){
  for (int i = 0; i < front; ++i){
    cout << q[i] << endl;
  }
}

template <class T>
T Queue<T>::get_item_at(int index){
  if (index <= max) {
    return q[index];
  }

  return -1;
}

template <class T>
T Queue<T>::get_front(){
  return this->q[this->front];
}

template <class T>
bool Queue<T>::is_empty() {
  if (rear <= 0) {
    return true;
  }

  return false;
}

template <class T>
bool Queue<T>::contains(T item) {
  for (int i = 0; i < rear; ++i) {
    if (this->q[i] == item) {
      return true;
    }
  }

  return false;
}
//End Class


int main(void) {
  Queue<string> *myQueue = new Queue<string>(100);
  myQueue->enqueue("Alex");
  myQueue->enqueue("Doug");
  myQueue->enqueue("Finance");
  myQueue->print_queue();
  try {
    cout << "REMOVED: " << myQueue->dequeue() << endl;
  } catch (const char* msg) {
    cout << msg << endl;
  }
  cout << "\n" << endl;
  myQueue->print_queue();
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

  return 0;
}
