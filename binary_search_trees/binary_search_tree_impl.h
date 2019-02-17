/**************************************
 * @class btree
 * @desc  Implements btree
 *************************************/
btree::btree(){
  root = NULL;
}

btree::~btree(){
  destroy_tree();
}

int btree::getBTreeSize(){
  return BTreeSize;
}

void btree::destroy_tree(node *leaf){
  if(leaf != NULL){
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf){

  if(key < leaf->value){
    if(leaf->left != NULL){
      insert(key, leaf->left);
    }else{
      leaf->left = new node;
      leaf->left->value = key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
      setBTreeSize(this->BTreeSize + 1);
    }
  }else if(key >= leaf->value){
    if(leaf->right != NULL){
      insert(key, leaf->right);
    }else{
      leaf->right = new node;
      leaf->right->value = key;
      leaf->right->right = NULL;
      leaf->right->left = NULL;
      setBTreeSize(this->BTreeSize + 1);
    }
  }
}

void btree::insert(int key){
  if(root != NULL){
    insert(key, root);
  }else{
    root = new node;
    root->value = key;
    root->left = NULL;
    root->right = NULL;
    setBTreeSize(1);
  }
}

void btree::setBTreeSize(int newSize) {
  BTreeSize = newSize;
}


node *btree::search(int key, node *leaf){
  if(leaf != NULL){
    if(key == leaf->value){
      return leaf;
    }
    if(key < leaf->value){
      return search(key, leaf->left);
    }else{
      return search(key, leaf->right);
    }
  }else{
    return NULL;
  }
}

node *btree::search(int key){
  return search(key, root);
}

void btree::destroy_tree(){
  destroy_tree(root);
}

void btree::inorder_print(){
  inorder_print(root);
  cout << "\n";
}

void btree::inorder_print(node *leaf){
  if(leaf != NULL){
    inorder_print(leaf->left);
    cout << leaf->value << ",";
    inorder_print(leaf->right);
  }
}

void btree::postorder_print(){
  postorder_print(root);
  cout << "\n";
}

void btree::postorder_print(node *leaf){
  if(leaf != NULL){
    inorder_print(leaf->left);
    inorder_print(leaf->right);
    cout << leaf->value << ",";
  }
}

void btree::preorder_print(){
  preorder_print(root);
  cout << "\n";
}

void btree::preorder_print(node *leaf){
  if(leaf != NULL){
    cout << leaf->value << ",";
    inorder_print(leaf->left);
    inorder_print(leaf->right);
  }
}

void btree::breadth_first_search(Queue<int> *myQueue){
  return breadth_first_search(root, myQueue);
}

void btree::breadth_first_search(node *leaf, Queue<int> *myQueue){
  vector<node> current;
  current.reserve(this->BTreeSize);
  current.push_back(*leaf);

  while (current.size() > 0) {
    vector<node> next;
    myQueue->enqueue(current[0].value);

    if (current[0].left){
      next.resize(1, *current[0].left);
    }

    if (current[0].right){
      next.resize(2, *current[0].right);
    }

    for(int i = 1; i < current.size(); i++){
      myQueue->enqueue(current[i].value);

      if(current[i].left){
        next.resize(next.size() + 1, *current[i].left);
      }

      if(current[i].right){
        next.resize(next.size() + 1, *current[i].right);
      }
    }

    if (next.size() != 0) {
      int add_size = next.size();
      vector<node> new_current;
      new_current.reserve(next.size());
      new_current = next;
      current = new_current;
    } else {
      current.clear();
    }
  }
}

void btree::depth_first_search(Stack<int> *myStack, string order){
  return btree::depth_first_search(root, myStack, order);
}

void btree::depth_first_search(node *leaf, Stack<int> *myStack, string order){
  if (order == "pre_order") {
    myStack->insert(leaf->value);
    if (leaf->left) {
      depth_first_search(leaf->left, myStack, order);
    }

    if (leaf->right) {
      depth_first_search(leaf->right, myStack, order);
    }
  } else if (order == "in_order") {
    if (leaf->left) {
      depth_first_search(leaf->left, myStack, order);
    }

    myStack->insert(leaf->value);

    if (leaf->right) {
      depth_first_search(leaf->right, myStack, order);
    }
  } else if (order == "post_order") {
    if (leaf->left) {
      depth_first_search(leaf->left, myStack, order);
    }

    if (leaf->right) {
      depth_first_search(leaf->right, myStack, order);
    }

    myStack->insert(leaf->value);
  }
}

bool btree::is_valid_bst() {
  return is_valid_bst(root, INT_MIN, INT_MAX);
}

bool btree::is_valid_bst(node *leaf, int min, int max) {
  if (leaf != NULL){
    return true;
  }

  if (leaf->value < min || leaf->value > max) {
    return false;
  }

  return (is_valid_bst(leaf->left, min, leaf->value - 1) && is_valid_bst(leaf->right, leaf->value + 1, max));
}

int btree::find_min() {
  return find_min(root, INT_MAX);
}

int btree::find_min(node *leaf, int min) {
  if (leaf == NULL) {
    return -1;
  }

  node *current_leaf = leaf;

  while(current_leaf != NULL) {
    min = current_leaf->value;
    current_leaf = current_leaf->left;
  }

  return min;
}

int btree::find_max() {
  return find_max(root, INT_MIN);
}

int btree::find_max(node *leaf, int max) {
  if (leaf == NULL) {
    return -1;
  }

  node *current_leaf = leaf;

  while(current_leaf != NULL) {
    max = current_leaf->value;
    current_leaf = current_leaf->right;
  }

  return max;
}
// End Class
