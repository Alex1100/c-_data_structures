#include <iostream>
#include <typeinfo>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;


template <class T, class E>
struct vertex_data{
  int weight;
  int heuristic;
}

template <class T, class E>
struct vertex{
  T key;
  vertex_data *value;
};

template <class T, class E>
struct node_data{
  T key;
  vertex_node *value;
};

template <class T, class E>
struct node{
  node_data<T, E> data;
  node<T, E> *next;
};

/**************************************
 * @class LinkedList
 * @desc  Implements LinkedList
 *************************************/
template <class T, class E>
class LinkedList {
private:
  node<T, E> *head;
  node<T, E> *tail;
  int size;
public:
  LinkedList() {
    head = new node<T, E>();
    tail = head;
    size = 0;
  };
  ~LinkedList() {
    node<T, E> *current_node = this->head;
    node<T, E> *prev_node;
    while(current_node != this->tail) {
      prev_node = current_node;
      current_node = current_node->next;
      delete prev_node;
    }

    delete this->tail;
  };
  int get_size();
  void add_node(T key, E val);
  node<T, E> *get_head();
  node<T, E> *get_tail();
  bool contains(T key);
  node<T, E> *remove_node(T key);
};

template <class T, class E>
int LinkedList<T, E>::get_size() {
  return size;
}

template <class T, class E>
void LinkedList<T, E>::add_node(T key, E val){
  if (this->size == 0) {
    node<T, E> *new_node = new node<T, E>();
    new_node->data.key = key;
    new_node->data.value = val;

    this->head = new_node;
    this->tail = new_node;
    this->size++;
  } else {
    node<T, E> *current_node = this->head;

    while(current_node->next != NULL) {
      current_node = current_node->next;
    }

    current_node->next = new node<T, E>();
    current_node->next->data.key = key;
    current_node->next->data.value = val;

    this->tail = current_node->next;
    this->size++;
  }
}

template <class T, class E>
bool LinkedList<T, E>::contains(T key) {
  if (this->size == 0) {
    return false;
  }

  node<T, E> *current_node = this->head;

  while(current_node->next != NULL) {
    if (current_node->data.key == key) {
      return true;
    }
    current_node = current_node->next;
  }

  return false;
}

template <class T, class E>
node<T, E> *LinkedList<T, E>::get_head() {
  return this->head;
}

template <class T, class E>
node<T, E> *LinkedList<T, E>::get_tail() {
  return this->tail;
}

template <class T, class E>
node<T, E> *LinkedList<T, E>::remove_node(T key) {
  if (this->size == 0) {
    throw "Empty List";
  }

  node<T, E> *removed_node = NULL;

  if (this->head->data.key == key) {
    removed_node = this->head;
    this->head = this->head->next;

    if (this->size == 1) {
      this->tail = NULL;
    }

    return removed_node;
  }

  node<T, E> *current_node = this->head;
  node<T, E> *prev_node;

  while(current_node->next != NULL) {
    prev_node = current_node;
    current_node = current_node->next;

    if (current_node->data.key == key) {
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
template <class T, class E>
class HashTable {
private:
  LinkedList<T, E> *storage;
  int front, rear, size, storage_limit;
  const int hash_salt = {11021992};
  void expand();
  void shrink();
public:
  HashTable(int initial_size) {
    front = 0;
    rear = initial_size - 1;
    size = 0;
    storage_limit = initial_size;
    storage = new LinkedList<T, E>[storage_limit];
  }
  ~HashTable(){
    delete []storage;
  }
  int get_size();
  int get_storage_limit();
  int hash(T key);
  void insert(T key, E val);
  node<T, E> *remove(T key);
  LinkedList<T, E> *get_bucket(int hash_key_index);
  bool is_int(T key);
  bool contains(T key);
};

template <class T, class E>
int HashTable<T, E>::get_size() {
  return size;
}

template <class T, class E>
int HashTable<T, E>::get_storage_limit() {
  return storage_limit;
}

template <class T, class E>
void HashTable<T, E>::expand() {
  int all_item_count = 0;
  int temp_vals_rear = 0;

  for (int i = 0; i < storage_limit; i++) {
    if (storage[i].get_size() > 0) {
      all_item_count += storage[i].get_size();
    }
  }

  node<T, E> *temp_vals = new node<T, E>[all_item_count];

  for (int j = 0; j < storage_limit; j++) {
    if (storage[j].get_size()) {
      node<T, E> *current_node = storage[j].get_head();

      while(current_node != NULL) {
        temp_vals[temp_vals_rear] = *(current_node);
        temp_vals_rear++;
        current_node = current_node->next;
      }
    }
  }

  size_t newSize = storage_limit * 2;
  LinkedList<T, E> *new_storage = new LinkedList<T, E>[newSize];

  memcpy(new_storage, storage, storage_limit * sizeof(LinkedList<T, E>));

  storage_limit = newSize;
  delete []storage;
  storage = new_storage;

  for (int s = 0; s < storage_limit; s++) {
    storage[s] = *(new LinkedList<T, E>());
  }

  size = 0;

  for (int v = 0; v < temp_vals_rear; v++) {
    insert(temp_vals[v].data.key, temp_vals[v].data.value);
  }
}

template <class T, class E>
void HashTable<T, E>::insert(T key, E val) {
  if (size == floor(storage_limit * 0.625)) {
    expand();
  }

  int storage_index = hash(key);

  if (!storage[storage_index].get_size()) {
    storage[storage_index].add_node(key, val);
    size++;
    return;
  }

  bool complete = false;
  node<T, E> *current_node = storage[storage_index].get_head();

  while(current_node != NULL && !complete) {
    if (current_node->data.key == key) {
      current_node->data.value = val;
      complete = true;
      return;
    }
    current_node = current_node->next;
  }

  storage[storage_index].add_node(key, val);
  size++;
}

template <class T, class E>
void HashTable<T, E>::shrink() {
  int all_item_count = 0;
  int temp_vals_rear = 0;

  for (int i = 0; i < storage_limit; i++) {
    if (storage[i].get_size() > 0) {
      all_item_count += storage[i].get_size();
    }
  }

  node<T, E> *temp_vals = new node<T, E>[all_item_count];

  for (int j = 0; j < storage_limit; j++) {
    if (storage[j].get_size()) {
      node<T, E> *current_node = storage[j].get_head();

      while(current_node != NULL) {
        temp_vals[temp_vals_rear] = *(current_node);
        temp_vals_rear++;
        current_node = current_node->next;
      }
    }
  }

  size_t newSize = floor(storage_limit / 2);
  LinkedList<T, E> *new_storage = new LinkedList<T, E>[newSize];

  memcpy(new_storage, storage, storage_limit * sizeof(LinkedList<T, E>));

  storage_limit = newSize;
  delete []storage;
  storage = new_storage;

  for (int s = 0; s < storage_limit; s++) {
    storage[s] = *(new LinkedList<T, E>());
  }

  size = 0;

  for (int v = 0; v < temp_vals_rear; v++) {
    insert(temp_vals[v].data.key, temp_vals[v].data.value);
  }
}

template <class T, class E>
node<T, E> *HashTable<T, E>::remove(T key) {
  if (size <= floor(storage_limit * 0.4)) {
    shrink();
  }

  int storage_index = hash(key);

  if (storage_index > storage_limit) {
    throw "Key does not exist";
  }

  if (storage[storage_index].contains(key)) {
    size--;
    return storage[storage_index].remove_node(key);
  } else {
    throw "Key does not exist";
  }
}

template <class T, class E>
LinkedList<T, E> *HashTable<T, E>::get_bucket(int hash_key_index) {
  return &storage[hash_key_index];
}

template <class T, class E>
int HashTable<T, E>::hash(T key) {
  int hashed_base = 0;
  stringstream ss;
  string converted_key;

  if (is_int(key)) {
    ss.str("");
    ss.clear();
    ss << key;
    converted_key = ss.str();
  } else {
    converted_key = key;
  }

  for (int i = 0; i < converted_key.length(); i++) {
    hashed_base = (hashed_base << 5) + hashed_base + int(converted_key[i]);
    hashed_base = hashed_base & hashed_base;
    hashed_base = abs(hashed_base << hash_salt);
  }

  return hashed_base % this->get_storage_limit();
}

template <class T, class E>
bool HashTable<T, E>::is_int(T key) {
  return (typeid(int) == typeid(key));
}

template <class T, class E>
bool HashTable<T, E>::contains(T key) {
  int storage_index = hash(key);
  if (
      storage_index > storage_limit
      || !storage[storage_index].get_size()
      || !storage[storage_index].contains(key)
  ) {
    return false;
  }

  return true;
}


/**************************************
 * @class Graph
 * @desc  Implements Graph
 *************************************/
template <class T, class E>
class Graph {
private:
  T *nodes_arr;
  HashTable<T, E> *vertexes;
public:

}

int main(void) {
  return 0;
}
