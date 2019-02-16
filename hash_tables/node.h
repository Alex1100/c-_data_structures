// node.h
#pragma once
#ifndef NODE_H
#define NODE_H
#include "node_data.h"
template <class T, class E>
struct node{
  node_data<T, E> data;
  node<T, E> *next;
};
#endif

