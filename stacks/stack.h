//  stack.h

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
public:
  Stack(int size=0){
    front = rear = 0;
    max = size;
    s = new T[size];
  }

  ~Stack(){
    delete []s;
  }

  int insert(T);
  T pop();
  T getItemAt(int index);
  bool isEmpty();
  int get_count_of_items();
private:
  int front, rear, max;
  T *s;
};


/**************************************
 * @class Stack
 * @desc  Implements Stack
 *************************************/
template <class T>
int Stack<T>::insert(T item){
  if (rear >= max) {
    return -2;
  }
  s[rear] = item;
  rear++;
  return 0;
}

template <class T>
T Stack<T>::pop(){
  if(rear<=0){
    return NULL;
  }
  T result = s[rear - 1];
  --rear;
  return result;
}

template <class T>
T Stack<T>::getItemAt(int index){
  if (index < rear) {
    return s[index];
  }

  return -1;
}

template <class T>
bool Stack<T>::isEmpty(){
  if (rear <= 0) {
    return true;
  }

  return false;
}

template <class T>
int Stack<T>::get_count_of_items(){
  return rear;
}
// End Class

#endif
