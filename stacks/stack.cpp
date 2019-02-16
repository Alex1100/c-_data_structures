#include <iostream>
#include "stack.h"
using namespace std;


int main(void){
    Stack<int> *ss = new Stack<int>(10);
    ss->insert(1);
    ss->insert(2);
    ss->insert(3);
    ss->insert(4);
    cout << ss->get_item_at(0) << "\n" << endl;
    cout << ss->get_item_at(1) << "\n" << endl;
    cout << ss->get_item_at(2) << "\n" << endl;
    cout << ss->get_item_at(3) << "\n\n" << endl;
    int someInt = {ss->pop()};
    int nextInt = {ss->pop()};
    cout << "INT RETURNED IS: " << someInt << "\n" << endl;
    cout << "NEXT INT IS: " << nextInt << endl;
    cout << "AND UP NEXT: " << ss->pop() << endl;
    cout << "AND UP NEXT: " << ss->pop() << endl;
    ss->~Stack();
    return 0;
}
