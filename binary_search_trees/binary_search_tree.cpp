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

  Queue<int> *qq = new Queue<int>(tree->getBTreeSize());
  tree->breadth_first_search(qq);

  cout << "\nBFS: " << endl;
  qq->print_queue();
  Stack<int> *ss = new Stack<int>(tree->getBTreeSize());
  tree->depth_first_search(ss, "in_order");
  cout << "\nDFS: " << endl;
  ss->print_stack();
  cout << "STACK IS EMPTY??: " << ss->is_empty() << endl;
  cout << "IS TREE VALID BST??:: " << tree->is_valid_bst() << endl;
  cout << "MIN IN TREE IS: " << tree->find_min() << endl;
  cout << "MAX IN TREE IS: " << tree->find_max() << endl;
  qq->~Queue();
  qq = NULL;
  ss->~Stack();
  ss = NULL;
  tree->~btree();
  tree = NULL;

  return 0;
}
