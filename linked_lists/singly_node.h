// singly_node.h
#pragma once
using namespace std;

#ifndef SINGLY_NODE_H
#define SINGLY_NODE_H

template <class T>
struct node{
  T data;
  node<T> *next;
};

#endif
