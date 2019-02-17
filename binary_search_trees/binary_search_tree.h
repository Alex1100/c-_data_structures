// binary_search_tree.h
#pragma once
#include <iostream>
#include <vector>
using namespace std;


#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "../queues/queue.h"
#include "../stacks/stack.h"
#include "./node.h"

class btree{
public:
  btree();
  ~btree();

  int getBTreeSize();
  void insert(int key);
  node *search(int key);
  void destroy_tree();
  void inorder_print();
  void postorder_print();
  void preorder_print();
  void breadth_first_search(Queue<int> *myQueue);
  void depth_first_search(Stack<int> *myStack, string order);
  bool is_valid_bst();
  int find_min();
  int find_max();

private:
  void setBTreeSize(int newSize);
  void destroy_tree(node *leaf);
  void insert(int key, node *leaf);
  node *search(int key, node *leaf);
  void inorder_print(node *leaf);
  void postorder_print(node *leaf);
  void preorder_print(node *leaf);
  void breadth_first_search(node *leaf, Queue<int> *myQueue);
  void depth_first_search(node *leaf, Stack<int> *myStack, string order);
  bool is_valid_bst(node *leaf, int min, int max);
  int find_min(node *leaf, int min);
  int find_max(node *leaf, int max);

  node *root;
  int BTreeSize;
};

#include "binary_search_tree_impl.h"

#endif
