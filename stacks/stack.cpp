#include <iostream>
#include "stack.h"
using namespace std;


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


int main(void){
    Stack<int> *myStack = new Stack<int>(10);
    myStack->insert(1);
    myStack->insert(2);
    myStack->insert(3);
    myStack->insert(4);
    myStack->printStack();
    cout << myStack->getItemAt(4) << endl;
    cout << myStack->getItemAt(1) << "\n\n" << endl;
    int someInt = {myStack->pop()};
    int nextInt = {myStack->pop()};
    cout << "INT RETURNED IS: " << someInt << endl;
    cout << "NEXT INT IS: " << nextInt << endl;
    cout << "AND UP NEXT: " << myStack->pop() << endl;
    cout << "AND UP NEXT: " << myStack->pop() << endl;
    cout << "\nHERE ON AFTER, SHOULD ONLY RETURN -1 FOR ERROR / EMPTY STACK" << endl;
    cout << "AND UP NEXT: " << myStack->pop() << endl;
    cout << "AND UP NEXT: " << myStack->pop() << endl;
    cout << "AND UP NEXT: " << myStack->pop() << endl;
    myStack->~Stack();
    return 0;
}
