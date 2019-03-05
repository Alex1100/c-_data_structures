/**************************************
 * @class HashTable
 * @desc  Implements HashTable
 *************************************/
template <class T, class E, class Y>
int HashTable<T, E, Y>::get_size() {
  return size;
}

template <class T, class E, class Y>
int HashTable<T, E, Y>::get_storage_limit() {
  return storage_limit;
}

template <class T, class E, class Y>
void HashTable<T, E, Y>::expand() {
  int all_item_count = 0;
  int temp_vals_rear = 0;

  for (int i = 0; i < storage_limit; i++) {
    if (storage[i].get_size() > 0) {
      all_item_count += storage[i].get_size();
    }
  }

  node<T, E, Y> *temp_vals = new node<T, E, Y>[all_item_count];

  for (int j = 0; j < storage_limit; j++) {
    if (storage[j].get_size()) {
      node<T, E, Y> *current_node = storage[j].get_head();

      while(current_node != NULL) {
        temp_vals[temp_vals_rear] = *(current_node);
        temp_vals_rear++;
        current_node = current_node->next;
      }
    }
  }

  size_t newSize = storage_limit * 2;
  LinkedList<T, E, Y> *new_storage = new LinkedList<T, E, Y>[newSize];

  memcpy(new_storage, storage, storage_limit * sizeof(LinkedList<T, E, Y>));

  storage_limit = newSize;
  delete []storage;
  storage = new_storage;

  for (int s = 0; s < storage_limit; s++) {
    storage[s] = *(new LinkedList<T, E, Y>());
  }

  size = 0;

  for (int v = 0; v < temp_vals_rear; v++) {
    insert(
      temp_vals[v].data.key,
      temp_vals[v].data.value,
      temp_vals[v].data.weight,
      temp_vals[v].data.heuristic
    );
  }
}

template <class T, class E, class Y>
void HashTable<T, E, Y>::insert(T key, E val, Y weight, Y heuristic) {
  if (size >= floor(storage_limit * 0.625)) {
    expand();
  }

  int storage_index = hash(key);

  if (!storage[storage_index].get_size()) {
    storage[storage_index].add_node(key, val, weight, heuristic);
    size++;
    return;
  }

  bool complete = false;
  node<T, E, Y> *current_node = storage[storage_index].get_head();
  while(current_node != NULL && !complete) {
    if (current_node->data.key == key) {
      current_node->data.value = val;
      current_node->data.weight = weight;
      current_node->data.heuristic = heuristic;
      complete = true;
      return;
    }
    current_node = current_node->next;
  }

  storage[storage_index].add_node(key, val, weight, heuristic);
  size++;
}

template <class T, class E, class Y>
void HashTable<T, E, Y>::shrink() {
  int all_item_count = 0;
  int temp_vals_rear = 0;

  for (int i = 0; i < storage_limit; i++) {
    if (storage[i].get_size() > 0) {
      all_item_count += storage[i].get_size();
    }
  }

  node<T, E, Y> *temp_vals = new node<T, E, Y>[all_item_count];

  for (int j = 0; j < storage_limit; j++) {
    if (storage[j].get_size()) {
      node<T, E, Y> *current_node = storage[j].get_head();

      while(current_node != NULL) {
        temp_vals[temp_vals_rear] = *(current_node);
        temp_vals_rear++;
        current_node = current_node->next;
      }
    }
  }

  size_t newSize = floor(storage_limit / 2);
  LinkedList<T, E, Y> *new_storage = new LinkedList<T, E, Y>[newSize];

  memcpy(new_storage, storage, storage_limit * sizeof(LinkedList<T, E, Y>));

  storage_limit = newSize;
  delete []storage;
  storage = new_storage;

  for (int s = 0; s < storage_limit; s++) {
    storage[s] = *(new LinkedList<T, E, Y>());
  }

  size = 0;

  for (int v = 0; v < temp_vals_rear; v++) {
    insert(
      temp_vals[v].data.key,
      temp_vals[v].data.value,
      temp_vals[v].data.weight,
      temp_vals[v].data.heuristic
    );
  }
}

template <class T, class E, class Y>
node<T, E, Y> *HashTable<T, E, Y>::remove(T key) {
  if (size <= floor(storage_limit * 0.4)) {
    shrink();
  }

  int storage_index = hash(key);

  if (storage_index > storage_limit) {
    throw runtime_error("Key does not exist");
  }

  if (storage[storage_index].contains(key)) {
    size--;
    return storage[storage_index].remove_node(key);
  } else {
    throw runtime_error("Key does not exist");
  }
}

template <class T, class E, class Y>
LinkedList<T, E, Y> *HashTable<T, E, Y>::get_bucket(int hash_key_index) {
  return &storage[hash_key_index];
}

template <class T, class E, class Y>
int HashTable<T, E, Y>::hash(T key) {
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

template <class T, class E, class Y>
bool HashTable<T, E, Y>::is_int(T key) {
  return (typeid(int) == typeid(key));
}

template <class T, class E, class Y>
bool HashTable<T, E, Y>::contains(T key) {
  int storage_index = hash(key);

  if (
      !storage[storage_index].get_size()
      || !storage[storage_index].contains(key)
  ) {
    return false;
  }

  return true;
}

template <class T, class E, class Y>
node<T, E, Y> *HashTable<T, E, Y>::get_entry(T key) {
  int storage_index = hash(key);
  try {
    return storage[storage_index].get_item(key);
  } catch (const runtime_error& error) {
    throw error;
  }
}

template <class T, class E, class Y>
LinkedList<T, E, Y> *HashTable<T, E, Y>::get_storage() {
  return storage;
}
// End Class
