#include <iostream>

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

template <class T>
node<T> *LinkedList<T>::get_tail() {
  return this->tail;
}

template <class T>
node<T> *LinkedList<T>::remove_node(T val) {
  if (this->size == 0) {
    throw "Empty List";
  }

  node<T> *removed_node = NULL;

  if (this->head->data == val) {
    removed_node = this->head;
    this->head = this->head->next;

    if (this->size == 1) {
      this->tail = NULL;
    }

    return removed_node;
  }

  node<T> *current_node = this->head;
  node<T> *prev_node;

  while(current_node->next != NULL) {
    prev_node = current_node;
    current_node = current_node->next;

    if (current_node->data == val) {
      removed_node = current_node;
      prev_node->next = current_node->next;
      if (removed_node == this->tail) {
        prev_node->next = NULL;
        this->tail = prev_node;
      }
    }
  }

  if (removed_node == NULL) {
    throw "Node does not exist";
  }

  return removed_node;
}


int main(void) {
  LinkedList<int> linked_list;
  linked_list.add_node(10);
  linked_list.add_node(30);
  linked_list.add_node(40);
  linked_list.add_node(50);
  linked_list.add_node(60);
  linked_list.add_node(70);

  cout << "LINKED LIST HEAD IS: " << linked_list.get_head()->data << endl;
  cout << "CONTAINS 20?:: " << linked_list.contains(20) << endl;
  cout << "CONTAINS 10?:: " << linked_list.contains(10) << endl;
  node<int> *deleted_node = linked_list.remove_node(70);
  try {
    node<int> *additional_deleted_node = linked_list.remove_node(90);
    cout << "NODE REMOVED IS: " << additional_deleted_node->data << endl;
  } catch (const char* msg) {
    cout << "ERROR REMOVING NODE:: " << msg << endl;
  }

  cout << "TAIL IS: " << linked_list.get_tail()->data << endl;
  linked_list.~LinkedList();
  linked_list = NULL;
}
