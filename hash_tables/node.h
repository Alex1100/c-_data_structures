// node.h
#pragma once
#ifndef NODE_H
#define NODE_H
#include "node_data.h"
template <class T, class E, class Y>
struct node{
  node_data<T, E, Y> data;
  node<T, E, Y> *next;
};
#endif

