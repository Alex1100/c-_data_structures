// linked_list.h
#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T, class E, class Y>
class LinkedList {
private:
  node<T, E, Y> *head;
  node<T, E, Y> *tail;
  int size;
public:
  LinkedList() {
    head = new node<T, E, Y>();
    tail = head;
    size = 0;
  };
  ~LinkedList() {
    node<T, E, Y> *current_node = this->head;
    node<T, E, Y> *prev_node;
    while(current_node != this->tail) {
      prev_node = current_node;
      current_node = current_node->next;
      delete prev_node;
    }

    delete this->tail;
  };
  int get_size();
  void add_node(T key, E val, Y weight, Y heuristic);
  node<T, E, Y> *get_head();
  node<T, E, Y> *get_tail();
  bool contains(T key);
  node<T, E, Y> *remove_node(T key);
  node<T, E, Y> *get_item(T key);
};

#include "linked_list_impl.h"

#endif
