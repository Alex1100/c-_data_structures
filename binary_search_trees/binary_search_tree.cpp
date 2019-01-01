#include <iostream>
#include <vector>

using namespace std;

struct node {
  int value;
  node *left;
  node *right;
};

class Queue
{
public:
  void enqueue(int item)
  {
    cout << "ITEMS ARE: " << this->Items[0] << endl;
    this->Items.push_back(item);
    setQueueSize(this->QueueSize + 1);
  }

  int dequeue()
  {
    int removed = this->Items[0];
    this->Items.erase(this->Items.begin(), this->Items.begin() + 1);
    return removed;
  }

  int front() const
  {
    return this->Items[0];
  }

  int back() const
  {
    return this->Items[this->QueueSize - 1];
  }

  bool contains(int item) const
  {
    for (int i = 0; i < sizeof(this->Items) / sizeof(this->Items[0]); ++i)
    {
      if (this->Items[i] == item)
      {
        return true;
      }
    }

    return false;
  }

  bool isEmpty()
  {
    return this->Items.empty();
  }

    void printQueue() const
  {
    // Forward (Normal)
    copy(
      begin(this->Items),
      end(this->Items),
      ostream_iterator<int>(cout, "\n")
    );
  }

  int getQueueSize() const
  {
    if (this->Items.empty())
    {
      return 0;
    }

    return this->QueueSize;
  }

  void setQueueSize(int newSize)
  {
    this->QueueSize = newSize;
  }

private:
  vector<int> Items;
  int QueueSize;
};

class btree{
public:
  btree();
  ~btree();

  void insert(int key);
  node *search(int key);
  void destroy_tree();
  void inorder_print();
  void postorder_print();
  void preorder_print();
  Queue *breadth_first_search(Queue *queue);

private:
  void setBTreeSize(int newSize);
  void destroy_tree(node *leaf);
  void insert(int key, node *leaf);
  node *search(int key, node *leaf);
  void inorder_print(node *leaf);
  void postorder_print(node *leaf);
  void preorder_print(node *leaf);
  Queue *breadth_first_search(node *leaf, Queue *queue);

  node *root;
  int BTreeSize;
};


btree::btree(){
  root = NULL;
}

btree::~btree(){
  destroy_tree();
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

Queue *btree::breadth_first_search(Queue *queue){
  return breadth_first_search(root, queue);
}

Queue *btree::breadth_first_search(node *leaf, Queue *queue){
  vector<node> current;
  current.reserve(this->BTreeSize);
  current.push_back(*leaf);
    cout << "DOESN'T BREAK HERE:: " << endl;

  while (current.size() > 0) {
    cout << "DOESN'T BREAK HERE:: " << endl;
    vector<node> next;
    cout << "DOESN'T BREAK HERE:: " << endl;
    queue->enqueue(current[0].value);
    cout << "BREAKS HERE:: " << endl;

    if (current[0].left){
      next.resize(1, *current[0].left);
    }

    if (current[0].right){
      next.resize(2, *current[0].right);
    }

    for(int i = 1; i < current.size(); i++){
      cout << "BREAKS HERE:: " << endl;

      queue->enqueue(current[i].value);

      if(current[i].left){
        cout << "SIZE BEFORE RESIZE IS: " << next.size() << endl;
        next.resize(next.size() + 1, *current[i].left);
        cout << "SIZE AFTER RESIZE IS: " << next.size() << endl;
      }

      if(current[i].right){
        next.resize(next.size() + 1, *current[i].right);
      }
      queue->printQueue();
    }
    cout << "BREAKS HERE:: " << endl;

    int add_size = next.size();
    vector<node> new_current;
    new_current.reserve(next.size());
    new_current = next;
    current = new_current;
  }

  return queue;
}

int main(){

  //btree tree;
  btree *tree = new btree();

  tree->insert(10);
  tree->insert(6);
  tree->insert(14);
  tree->insert(5);
  tree->insert(8);
  tree->insert(11);
  tree->insert(18);

  tree->preorder_print();
  tree->inorder_print();
  tree->postorder_print();
  Queue *myQueue = new Queue();
  cout << "DOESN'T BREAK HERE:: " << endl;
  myQueue = tree->breadth_first_search(myQueue);
  cout << "\n\nYO MY QUEUE AT END IS: " << endl;
  cout << "\nQUEUE ITEM #1 IS: " << myQueue->dequeue() << endl;
  myQueue->printQueue();
  // tree->~btree();
  // tree = NULL;
}
