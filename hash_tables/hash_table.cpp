#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct node{
  T data;
  node<T> *next;
};

/**************************************
 * @class LinkedList
 * @desc  Implements LinkedList
 *************************************/
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

/**************************************
 * @class HashTable
 * @desc  Implements HashTable
 *************************************/
template <class T>
class HashTable {
private:
  LinkedList<T> *storage;
  int front, rear, size;
public:
  HashTable(int initial_size) {
    front = 0;
    rear = initial_size - 1;
    size = initial_size;
    storage = new LinkedList<T>[size];
  }
  ~HashTable(){
    delete []storage;
  }
  int get_size();
  void add_to_ht(T val);
  LinkedList<T> get_bucket(int hash_key_index);
};

template <class T>
int HashTable<T>::get_size() {
  return size;
}

template <class T>
void HashTable<T>::add_to_ht(T val) {
  storage[0].add_node(val);
}

template <class T>
LinkedList<T> HashTable<T>::get_bucket(int hash_key_index) {
  return storage[hash_key_index];
}
//work in progress :)

int main(void) {
  HashTable<string> *myHashTable = new HashTable<string>(10);
  cout << "HASH TABLE SIZE IS: " << myHashTable->get_size() << endl;
  myHashTable->add_to_ht("Hi");
  LinkedList<string> myStorage = myHashTable->get_bucket(0);
  cout << "HASH TABLE ITEM SHOULD BE: " << myStorage.get_head()->data << endl;
  return 0;
}
