#include "./binary_search_tree.h"

int main(void){
  btree *tree = new btree();

  tree->insert(10);
  tree->insert(6);
  tree->insert(11);
  tree->insert(18);
  tree->insert(8);
  tree->insert(5);
  tree->insert(14);

  tree->preorder_print();
  tree->inorder_print();
  tree->postorder_print();

  Queue<int> *myQueue = new Queue<int>(tree->getBTreeSize());
  tree->breadth_first_search(myQueue);

  cout << "\nBFS: " << endl;
  myQueue->print_queue();
  Stack<int> *myStack = new Stack<int>(tree->getBTreeSize());
  tree->depth_first_search(myStack, "in_order");
  cout << "\nDFS: " << endl;
  myStack->print_stack();
  cout << "STACK IS EMPTY??: " << myStack->is_empty() << endl;
  cout << "IS TREE VALID BST??:: " << tree->is_valid_bst() << endl;
  cout << "MIN IN TREE IS: " << tree->find_min() << endl;
  cout << "MAX IN TREE IS: " << tree->find_max() << endl;
  myQueue->~Queue();
  myQueue = NULL;
  myStack->~Stack();
  myStack = NULL;
  tree->~btree();
  tree = NULL;

  return 0;
}
