/**************************************
 * @class Stack
 * @desc  Implements Stack
 *************************************/
template <class T>
int Stack<T>::insert(T item){
  if (rear >= max) {
    return -2;
  }
  s[rear] = item;
  rear++;
  return 0;
}

template <class T>
T Stack<T>::pop(){
  if(rear<=0){
    return NULL;
  }
  T result = s[rear - 1];
  --rear;
  return result;
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

template <class T>
int Stack<T>::get_count_of_items(){
  return rear;
}
// End Class
