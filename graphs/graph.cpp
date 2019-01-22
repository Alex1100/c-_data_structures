#include <iostream>
#include <typeinfo>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;


struct vertex_data{
  int weight;
  int heuristic;
};

template <class E>
struct vertex{
  E key;
  vertex_data *value;
  int rear;
};

template <class T, class E>
struct node_data{
  T key;
  vertex<E> *value[];
};

template <class T, class E>
struct node{
  node_data<T, E> data;
  node<T, E> *next;
};


/**************************************
 * @class Stack
 * @desc  Implements Stack
 *************************************/
template <class T>
class Stack{
private:
  int front, rear, max;
  T *s;
public:
  Stack(int size=0){
    front = rear = 0;
    max = size;
    s = new T[size];
  }

  ~Stack(){
    delete []s;
  }

  int insert(T);
  T pop();
  T printStack();
  T getItemAt(int index);
  bool isEmpty();
};

template <class T>
int Stack<T>::insert(T item){
  if (rear >= max) {
    return -2;
  }
  s[rear] = item;
  rear++;
}

template <class T>
T Stack<T>::pop(){
  if(rear<=0){
    return -1;
  }
  T result = s[rear - 1];
  --rear;
  return result;
}

template <class T>
T Stack<T>::printStack(){
  for (int i = 0; i < rear; ++i){
    cout << s[i] << endl;
  }
}

template <class T>
T Stack<T>::getItemAt(int index){
  if (index < rear) {
    return s[index];
  }

  return -1;
}

template <class T>
bool Stack<T>::isEmpty(){
  if (rear <= 0) {
    return true;
  }

  return false;
}
// End Class

/**************************************
 * @class Queue
 * @desc  Implements Queue
 *************************************/
template <class T>
class Queue{
private:
  int front, rear, max;
  T *q;
public:
  Queue(int size=0){
    front = rear = 0;
    max = size;
    q = new T[size];
  }
  ~Queue(){
    delete []q;
  }
  T get_front();
  T dequeue();
  T get_item_at(int index);
  void print_queue();
  void enqueue(T);
  bool contains(T item);
  bool is_empty();
};


template <class T>
void Queue<T>::enqueue(T elem){
  if(front >= max){
    throw "Out of space. Reallocate memory";
  }
  q[rear] = elem; rear++;
}

template <class T>
T Queue<T>::dequeue(){
  if(this->is_empty()){
    throw "Empty Queue";
  }

  T result = q[front];
  for (int i = 0; i < rear; i++) {
    swap(q[i], q[i + 1]);
  }

  --rear;
  return result;

}

template <class T>
void Queue<T>::print_queue(){
  for (int i = 0; i < front; ++i){
    cout << q[i] << endl;
  }
}

template <class T>
T Queue<T>::get_item_at(int index){
  if (index <= max) {
    return q[index];
  }

  return -1;
}

template <class T>
T Queue<T>::get_front(){
  return this->q[this->front];
}

template <class T>
bool Queue<T>::is_empty() {
  if (rear <= 0) {
    return true;
  }

  return false;
}

template <class T>
bool Queue<T>::contains(T item) {
  for (int i = 0; i < rear; ++i) {
    if (this->q[i] == item) {
      return true;
    }
  }

  return false;
}
//End Class


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
  void add_weight(T key, E val, int weight);
  void add_heuristic(T key, E val, int heuristic);
  node<T, E> *get_head();
  node<T, E> *get_tail();
  bool contains(T key);
  node<T, E> *remove_node(T key);
  vertex<E> *remove_vertex(T key, E vertex_key);
  node<T, E> *get_node(T key);
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
    new_node->data.value = new vertex<E>();
    new_node->data.value->vertex->key = val;
    new_node->data.value->vertex->rear = 0;
    int last_index = new_node->data.value->vertex->rear;
    new_node->data.value->vertex->value[last_index] = new vertex_data();
    new_node->data.value->vertex->rear++;

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
    current_node->next->data.value = new vertex<E>();
    current_node->next->data.value->vertex->key = val;
    current_node->data.value->vertex->rear = 0;
    int last_index = current_node->data.value->vertex->rear;
    current_node->next->data.value->vertex->value[last_index] = new vertex_data();
    current_node->data.value->vertex->rear++;

    this->tail = current_node->next;
    this->size++;
  }
}

template <class T, class E>
void LinkedList<T, E>::add_weight(T key, E vertex_key, int weight){

  if (this->size == 0) {
    throw "Vertex Does Not Exist";
  } else {

    node<T, E> *current_node = get_node(key);
    bool completed = false;
    int last_index = current_node->data.value->vertex;

    for (int i = 0; i < current_node->data.value->vertex->rear; i++) {
      if (current_node->data.value->vertex->value[i]->key == vertex_key) {
        current_node->data.value->vertex->value[i]->value->weight = weight;
        completed = true;
      }

      if (completed) {
        return;
      }
    }
  }
}

template <class T, class E>
void LinkedList<T, E>::add_heuristic(T key, E vertex_key, int heuristic){

  if (this->size == 0) {
    throw "Vertex Does Not Exist";
  } else {

    node<T, E> *current_node = get_node(key);
    bool completed = false;
    int last_index = current_node->data.value->vertex;

    for (int i = 0; i < current_node->data.value->vertex->rear; i++) {
      if (current_node->data.value->vertex->value[i]->key == vertex_key) {
        current_node->data.value->vertex->value[i]->value->heuristic = heuristic;
        completed = true;
      }

      if (completed) {
        return;
      }
    }
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

template <class T, class E>
node<T, E> *LinkedList<T, E>::get_node(T key) {
  if (this->size == 0) {
    return NULL;
  }

  node<T, E> *current_node = this->head;

  while(current_node->next != NULL) {
    if (current_node->data.key == key) {
      return current_node;
    }
    current_node = current_node->next;
  }
}

template <class T, class E>
vertex<E> *LinkedList<T, E>::remove_vertex(T key, E vertex_key) {
  if (this->size == 0) {
    throw "Empty List";
  }
  node<T, E> *current_node = NULL;
  vertex<E> *removed_vertex = NULL;

  if (contains(key)) {
    current_node = this->head;
    node<T, E> *prev_node;
    bool start_swap = false;

    if (current_node->data.key == key) {
      while(current_node->data.value->vertex) {
        for (int i = 0; i < current_node->data.value->vertex->rear; i++) {
          if (current_node->data.value->vertex[i]->key == vertex_key) {
            removed_vertex = current_node->data.value->vertex[i];
            start_swap = true;
          }

          if (start_swap) {
            swap(
              current_node->data.value->vertex[i],
              current_node->data.value->vertex[i + 1]);
          }
        }

        if (removed_vertex != NULL) {
          current_node->data.value->vertex->rear--;
        }
      }
    } else {
      while(current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;

        if (current_node->data.key == key) {
          while(current_node->data.value->vertex) {
            for (int i = 0; i < current_node->data.value->vertex->rear; i++) {
              if (current_node->data.value->vertex[i]->key == vertex_key) {
                removed_vertex = current_node->data.value->vertex[i];
                start_swap = true;
              }

              if (start_swap) {
                swap(
                  current_node->data.value->vertex[i],
                  current_node->data.value->vertex[i + 1]);
              }
            }

            if (removed_vertex != NULL) {
              current_node->data.value->vertex->rear--;
            }
          }
        }
      }
    }
  }

  if (removed_vertex == NULL) {
    throw "Vertex does not exist";
  }

  return removed_vertex;
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
  cout << "WHATT: " << storage_limit << endl;
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
  HashTable<T, E> *vertexes;
  T *nodes_arr;
  int front, rear, size;
  void depth_first_search(T source_vertex, HashTable<T, E> *visited, Stack<T> *visited_data);
  void breadth_first_search(T source_vertex, Queue<T> *result, HashTable<T, E> *visited, Queue<T> *node_queue);
public:
  Graph(int initial_size) {
    front = 0;
    rear = initial_size -1;
    size = 0;
    nodes_arr = new T[initial_size];
    HashTable<T, E> *vertexes = new HashTable<T, E>(initial_size);
  }
  ~Graph() {
    cout << "REACHES HERE" << endl;
    vertexes->~HashTable();
    cout << "GETS HERE THOO" << endl;
    delete []nodes_arr;
  }
  void add_vertex(T vertex);
  void add_edge(T from, E to);
  void add_edges(T from, E to);
  void add_edge_weight(T from, E to);
  void add_edge_weights(T from, E to);
  void add_heuristic_cost(T from, E to);
  void add_heuristic_costs(T from, E to);
  void remove_edge(T from, E to);
  void depth_first_search(T vertex, Stack<T> *visited_data);
  void breadth_first_search(T vertex, Queue<T> *result);
  bool contains_vertex(T vertex);
  bool has_edge(T from, E to);
  bool same_vertexes(T from, E to);
  bool has_all_edges(T from, E to);
  int cost_length(T from, E to);
  int heuristic_length(T from, E to);
  vertex<E> *remove_vertex(T vertex);
  HashTable<T, E> *get_vertexes();
};

template <class T, class E>
HashTable<T, E> *Graph<T, E>::get_vertexes() {
  return vertexes;
}
// End Class

int main(void) {
  Graph<string, string> *graph_instance = new Graph<string, string>(20);
  cout << "Got here and properly initialized Graph" << endl;
  HashTable<string, string> *ht = graph_instance->get_vertexes();
  ht->insert("02qled_ad-ke9t_0ru", "Alex");
  return 1;
}
