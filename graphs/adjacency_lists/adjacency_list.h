// adjacency_list.h
#pragma once

#include <iostream>

using namespace std;

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include "../../stacks/stack.h"
#include "../../queues/queue.h"
#include "../../hash_tables/hash_table.h"

template <class T, class U>
class AdjacencyList {
private:
  int front, rear, max;
  HashTable<T, T, U> *adjacency_list;
  T *node_list;
  void dfs_helper(T source_vertex, Stack<T> *visited);
  void bfs_helper(T source_vertex, Queue<T> *result, HashTable<T, T, U> *visited, Queue<T> *node_queue);
public:
  AdjacencyList(int size=10) {
    this->adjacency_list = new HashTable<T, T, U>(size);
    front = rear = 0;
    max = size;
    node_list = new T[size];
  }
  ~AdjacencyList() {
    this->adjacency_list->~HashTable();
    delete []node_list;
  }
  void add_vertex(T vertex, U weight, U heuristic);
  void add_edge(T from, T to);
  void add_edges(T from, T to);
  void remove_edge(T from, T to);
  Stack<T> *depth_first_search(T vertex);
  void breadth_first_search(T vertex, Queue<T> *result);
  bool has_vertex(T vertex);
  bool has_edge(T from, T to);
  bool same_vertexes(T from, T to);
  bool has_all_edges(T from, T to);
  int cost_length(T from, T to);
  int heuristic_length(T from, T to);
  HashTable<T, T, U> *remove_vertex(T vertex);
  node<T, T, U> *get_item(T vertex);
};

#include "adjacency_list_impl.h"

#endif
