// singly_linked_list.h
#pragma once
using namespace std;

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include "singly_node.h"

template <class T>
class LinkedList {
private:
  node<T> *head;
  node<T> *tail;
  int size;
public:
  LinkedList() {
    head = new node<T>();
    tail = head;
    size = 0;
  };
  ~LinkedList() {
    node<T> *current_node = this->head;
    node<T> *prev_node;
    while(current_node != this->tail) {
      prev_node = current_node;
      current_node = current_node->next;
      delete prev_node;
    }

    delete this->tail;
  };
  void add_node(T val);
  node<T> *get_head();
  node<T> *get_tail();
  bool contains(T val);
  node<T> *remove_node(T val);
};

#include "singly_linked_list_impl.h"
#endif


