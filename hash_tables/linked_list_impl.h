/**************************************
 * @class LinkedList
 * @desc  Implements LinkedList
 *************************************/
template <class T, class E, class Y>
int LinkedList<T, E, Y>::get_size() {
  return size;
}

template <class T, class E, class Y>
void LinkedList<T, E, Y>::add_node(T key, E val, Y weight, Y heuristic){
  if (this->size == 0) {
    node<T, E, Y> *new_node = new node<T, E, Y>();
    new_node->data.key = key;
    new_node->data.value = val;
    new_node->data.weight = weight;
    new_node->data.heuristic = heuristic;

    this->head = new_node;
    this->tail = new_node;
    this->size++;
    return;
  } else {
    node<T, E, Y> *current_node = this->head;
    node<T, E, Y> *prev_node = this->head;

    while(current_node->next != NULL) {
      prev_node = current_node;
      current_node = current_node->next;
    }

    prev_node->next = new node<T, E, Y>();
    prev_node->next->data.key = key;
    prev_node->next->data.value = val;
    prev_node->next->data.weight = weight;
    prev_node->next->data.heuristic = heuristic;

    this->tail = prev_node->next;
    this->size++;
    return;
  }
}

template <class T, class E, class Y>
bool LinkedList<T, E, Y>::contains(T key) {
  if (this->size == 0) {
    return false;
  }

  node<T, E, Y> *current_node = get_head();

  if (current_node->data.key == key) {
    return true;
  }

  while(current_node != NULL) {
    if (current_node->data.key == key) {
      return true;
    }
    current_node = current_node->next;
  }

  return false;
}

template <class T, class E, class Y>
node<T, E, Y> *LinkedList<T, E, Y>::get_head() {
  return this->head;
}

template <class T, class E, class Y>
node<T, E, Y> *LinkedList<T, E, Y>::get_tail() {
  return this->tail;
}

template <class T, class E, class Y>
node<T, E, Y> *LinkedList<T, E, Y>::remove_node(T key) {
  if (this->size == 0) {
    throw runtime_error("Empty List");
  }

  node<T, E, Y> *removed_node = NULL;

  if (this->head->data.key == key) {
    removed_node = this->head;
    this->head = this->head->next;

    if (this->size == 1) {
      this->tail = NULL;
    }

    size--;
    return removed_node;
  }

  node<T, E, Y> *current_node = this->head;
  node<T, E, Y> *prev_node;

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
    throw runtime_error("Node does not exist");
  }

  size--;
  return removed_node;
}

template <class T, class E, class Y>
node<T, E, Y> *LinkedList<T, E, Y>::get_item(T key) {
  if (this->size == 0) {
    throw runtime_error("Empty List");
  }

  node<T, E, Y> *current_node = this->head;

  if (current_node->data.key == key) {
    return current_node;
  }

  while(current_node->next != NULL) {
    if (current_node->data.key == key) {
      return current_node;
    }
    current_node = current_node->next;
  }

  throw runtime_error("Item is not found in the list");
}

template <class T, class E, class Y>
node<T, E, Y> *LinkedList<T, E, Y>::get_item_at(int index) {
  if (this->size == 0) {
    throw runtime_error("Empty List");
  }

  if (index < 0 || index > this->size) {
    throw runtime_error("Index provided is out of bounds");
  }

  node<T, E, Y> *current_node = this->head;

  if (index == 0) {
    return current_node;
  }
  int count = 0;

  while(current_node->next != NULL) {
    if (index == count) {
      return current_node;
    }

    current_node = current_node->next;
    count++;
  }
}
// End Class
