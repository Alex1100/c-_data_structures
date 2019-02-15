#include <iostream>
#include "singly_linked_list.h"
using namespace std;


int main(void) {
  LinkedList<int> *linked_list = new LinkedList<int>();
  linked_list->add_node(10);
  linked_list->add_node(30);
  linked_list->add_node(40);
  linked_list->add_node(50);
  linked_list->add_node(60);
  linked_list->add_node(70);

  cout << "LINKED LIST HEAD IS: " << linked_list->get_head()->data << endl;
  cout << "CONTAINS 20?:: " << linked_list->contains(20) << endl;
  cout << "CONTAINS 10?:: " << linked_list->contains(10) << endl;
  node<int> *deleted_node = linked_list->remove_node(70);
  try {
    node<int> *additional_deleted_node = linked_list->remove_node(90);
    cout << "NODE REMOVED IS: " << additional_deleted_node->data << endl;
  } catch (const char* msg) {
    cout << "ERROR REMOVING NODE:: " << msg << endl;
  }

  cout << "TAIL IS: " << linked_list->get_tail()->data << endl;
  linked_list->~LinkedList();
  linked_list = NULL;
}
