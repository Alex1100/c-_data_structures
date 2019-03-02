// adjacency_list.h
#pragma once

#include <iostream>

using namespace std;

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include "../../stacks/stack.h"
#include "../../queues/queue.h"
#include "../../hash_tables/hash_table.h"

template <class T>
class AdjacencyList {
private:
  int front, rear, max;
  HashTable<T, T> *adjacency_list;
  T *node_list;
  void depth_first_search(T source_vertex, HashTable<T, T> *visited, Stack<T> *visited_data);
  void breadth_first_search(T source_vertex, Queue<T> *result, HashTable<T, T> *visited, Queue<T> *node_queue);
public:
  AdjacencyList(int size=10) {
    this->adjacency_list = new HashTable<T, T>(size);
    front = rear = 0;
    max = size;
    node_list = new T[size];
  }
  ~AdjacencyList() {
    this->adjacency_list->~HashTable();
    delete []node_list;
  }
  void add_vertex(T vertex);
  void add_edge(T from, T to);
  void add_edges(T from, T to);
  void add_edge_weight(T from, T to);
  void add_edge_weights(T from, T to);
  void add_heuristic_cost(T from, T to);
  void add_heuristic_costs(T from, T to);
  void remove_edge(T from, T to);
  void depth_first_search(T vertex, Stack<T> *visited_data);
  void breadth_first_search(T vertex, Queue<T> *result);
  bool has_vertex(T vertex);
  bool has_edge(T from, T to);
  bool same_vertexes(T from, T to);
  bool has_all_edges(T from, T to);
  int cost_length(T from, T to);
  int heuristic_length(T from, T to);
  HashTable<T, T> *remove_vertex(T vertex);
};

#include "adjacency_list_impl.h"

#endif
