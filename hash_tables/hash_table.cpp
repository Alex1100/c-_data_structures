#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <sstream>

using namespace std;

template <class T, class E>
struct node_data{
  T key;
  E value;
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
  void add_node(T key, E val);
  node<T, E> *get_head();
  node<T, E> *get_tail();
  bool contains(T key);
  node<T, E> *remove_node(T key);
};

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

  if (this->size == 1) {
    if (key == this->head->data.key) {
      return true;
    }

    return false;
  }

  node<T, E> *current_node = this->head;

  while(current_node->next != NULL) {
    current_node = current_node->next;
    if (current_node->data.key == key) {
      return true;
    }
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
  int front, rear, size;
  const int hash_salt = {11021992};
public:
  HashTable(int initial_size) {
    front = 0;
    rear = initial_size - 1;
    size = initial_size;
    storage = new LinkedList<T, E>[size];
  }
  ~HashTable(){
    delete []storage;
  }
  int get_size();
  void insert(T key, E val);
  LinkedList<T, E> *get_bucket(int hash_key_index);
  int hash(T key);
  bool is_int(T key);
};

template <class T, class E>
int HashTable<T, E>::get_size() {
  return size;
}

template <class T, class E>
void HashTable<T, E>::insert(T key, E val) {
  int storage_index = hash(key);
  storage[storage_index].add_node(key, val);
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

  for (int i = 0; i < (sizeof(converted_key) / sizeof(converted_key[0])); i++) {
    hashed_base = (hashed_base << 5) + hashed_base + int(converted_key[i]);
    hashed_base = hashed_base & hashed_base;
    hashed_base = abs(hashed_base << hash_salt);
  }

  return hashed_base % this->get_size();
}

template <class T, class E>
bool HashTable<T, E>::is_int(T key) {
  return (typeid(int) == typeid(key));
}

int main(void) {
  HashTable<string, int> *myHashTable = new HashTable<string, int>(10);
  cout << "HASH TABLE SIZE IS: " << myHashTable->get_size() << endl;
  myHashTable->insert("cloth", 100);
  LinkedList<string, int> *myStorage = myHashTable->get_bucket(6);
  cout << "HASH TABLE ITEM ENTERED KEY SHOULD BE: " << myStorage->get_head()->data.key << endl;
  cout << "HASH TABLE ITEM ENTERED VALUE SHOULD BE: " << myStorage->get_head()->data.value << endl;

  return 0;
}
