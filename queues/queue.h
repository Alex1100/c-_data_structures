// queue.h
#pragma once
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

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
  void enqueue(T);
  bool contains(T item);
  bool is_empty();
  void print_queue();
};

#include "queue_impl.h"

#endif
