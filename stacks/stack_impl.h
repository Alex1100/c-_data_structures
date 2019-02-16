/**************************************
 * @class Stack
 * @desc  Implements Stack
 *************************************/
template <class T>
int Stack<T>::insert(T item){
  if (rear >= max) {
    throw runtime_error("Out of space. Please allocate more memory.");
  }

  s[rear] = item;
  for (int i = rear; i > 0; i--) {
    swap(s[i], s[i - 1]);
  }
  rear++;
  return 0;
}

template <class T>
T Stack<T>::pop(){
  if(rear<=0){
    throw runtime_error("Empty Stack.");
  }

  T result = s[front];
  for (int i = 0; i < rear; i++) {
    swap(s[i], s[i + 1]);
  }
  --rear;
  return result;
}

template <class T>
T Stack<T>::get_item_at(int index){
  if (this->is_empty()) {
    throw runtime_error("Empty Stack.");
  }

  if (index > rear) {
    throw runtime_error("Index outside range.");
  }

  return s[index];
}

template <class T>
bool Stack<T>::is_empty(){
  if (rear <= 0) {
    return true;
  }

  return false;
}

template <class T>
int Stack<T>::get_count_of_items(){
  return rear;
}
// End Class
