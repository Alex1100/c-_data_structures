// node_data.h
#pragma once
#ifndef NODE_DATA_H
#define NODE_DATA_H
template <class T, class E, class Y>
struct node_data{
  T key;
  E value;
  Y weight;
  Y heuristic;
};
#endif
