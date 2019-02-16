/**************************************
 * @class HashTable
 * @desc  Implements HashTable
 *************************************/
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
// End Class
