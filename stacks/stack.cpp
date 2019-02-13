#include <iostream>
#include "stack.h"
using namespace std;


int main(void){
    Stack<int> *myStack = new Stack<int>(10);
    myStack->insert(1);
    myStack->insert(2);
    myStack->insert(3);
    myStack->insert(4);
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
