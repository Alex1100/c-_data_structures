//  stack.h
#pragma once
using namespace std;

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
public:
  Stack(int size=0){
    front = 0;
    stack_rear = 0;
    max = size;
    s = new T[size];
    stack_count = 0;
  }

  ~Stack(){
    delete []s;
  }

  void insert(T item);
  T pop();
  T get_item_at(int index);
  bool is_empty();
  int get_count_of_items();
  void print_stack();
  T *get_items();
  bool contains(T item);
private:
  int front, stack_rear, max, stack_count;
  T *s;
};


#include "stack_impl.h"

#endif
