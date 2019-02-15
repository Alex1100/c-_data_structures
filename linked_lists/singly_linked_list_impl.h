/**************************************
 * @class LinkedList
 * @desc  Implements LinkedList
 *************************************/
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

  node<T> *current_node = this->head;
  if (current_node->data == val) {
    return true;
  }

  while(current_node->next != NULL) {
    if (current_node->data == val) {
      return true;
    }
    current_node = current_node->next;
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
    throw runtime_error("Empty List");
  }

  node<T> *removed_node = NULL;

  if (this->head->data == val) {
    removed_node = this->head;
    this->head = this->head->next;

    if (this->size == 1) {
      this->tail = NULL;
    }
    this->size--;

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
  this->size--;

  return removed_node;
}
// End Class
