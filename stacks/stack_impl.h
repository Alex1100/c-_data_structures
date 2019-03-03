/**************************************
 * @class Stack
 * @desc  Implements Stack
 *************************************/
template <class T>
void Stack<T>::print_stack(){
  for (int i = stack_rear - 1; i >= 0; --i){
    cout << s[i] << endl;
  }
}

template <class T>
void Stack<T>::insert(T item){
  if (stack_rear >= max) {
    throw runtime_error("Out of space. Please allocate more memory.");
  }

  s[stack_rear] = item;

  for (int i = stack_rear; i > 0; i--) {
    swap(s[i], s[i - 1]);
  }

  stack_rear++;
  stack_count++;
}

template <class T>
T Stack<T>::pop(){
  if(stack_rear <= 0){
    throw runtime_error("Empty Stack.");
  }

  T result = s[front];
  for (int i = 0; i < stack_rear; i++) {
    swap(s[i], s[i + 1]);
  }
  stack_rear--;
  stack_count--;
  return result;
}

template <class T>
T Stack<T>::get_item_at(int index){
  if (this->is_empty()) {
    throw runtime_error("Empty Stack.");
  }

  if (index > stack_rear) {
    throw runtime_error("Index outside range.");
  }

  return s[index];
}

template <class T>
bool Stack<T>::is_empty(){
  if (stack_count == 0) {
    return true;
  }

  return false;
}

template <class T>
int Stack<T>::get_count_of_items(){
  return stack_rear;
}

template <class T>
T *Stack<T>::get_items() {
  return s;
}

template <class T>
bool Stack<T>::contains(T item) {
  for (int i = 0; i < stack_rear; i++) {
    if (s[i] == item) {
      return true;
    }
  }

  return false;
}
// End Class
