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


#include "stack_impl.h"

#endif
