#include <iostream>
#include <vector>

using namespace std;


template <class T>
struct node{
  T data;
  node<T> *next;
};

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
  }
  void add_node(T val);
  node<T> *get_head();
  bool contains(T val);
};

template <class T>
void LinkedList<T>::add_node(T val){
  if (this->size == 0) {
    node<T> *new_node = new node<T>();
    new_node->data = val;
    this->head = new_node;
    this->tail = new_node;
    this->size++;
  } else {
    node<T> *current_node = this->head;

    while(current_node->next != NULL) {
      current_node = current_node->next;
    }

    current_node->next = new node<T>();
    current_node->next->data = val;
    this->tail = current_node->next;
    this->size++;
  }
}

template <class T>
bool LinkedList<T>::contains(T val) {
  if (this->size == 0) {
    return false;
  }

  if (this->size == 1) {
    if (val == this->head->data) {
      return true;
    }

    return false;
  }

  node<T> *current_node = this->head;

  while(current_node->next != NULL) {
    current_node = current_node->next;
    if (current_node->data == val) {
      return true;
    }
  }

  return false;
}

template <class T>
node<T> *LinkedList<T>::get_head() {
  return this->head;
}


int main(void) {
  LinkedList<int> linked_list;
  linked_list.add_node(10);
  cout << "LINKED LIST HEAD IS: " << linked_list.get_head()->data << endl;
  cout << "CONTAINS 20?:: " << linked_list.contains(20) << endl;
  cout << "CONTAINS 10?:: " << linked_list.contains(10) << endl;
}
