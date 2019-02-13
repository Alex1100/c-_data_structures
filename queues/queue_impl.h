/**************************************
 * @class Queue
 * @desc  Implements Queue
 *************************************/
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
