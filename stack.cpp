#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
  void insert(string item)
  {
    this->Items.push_back(item);
    setNewSize(this->ItemSize + 1);
  }

  string pop()
  {
    setNewSize(this->ItemSize - 1);
    string poppedItem = this->Items.back();
    this->Items.pop_back();
    return poppedItem;
  }

  bool contains(string item)
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

  string peek() const
  {
    return this->Items[sizeof(this->Items) / sizeof(this->Items[0]) - 1];
  }

  bool isEmpty()
  {
    return this->Items.empty();
  }

  void setNewSize(int new_size)
  {
    ItemSize = new_size;
  }

  void printStack() const
  {
    // Forward (Normal)
    copy(
      begin(this->Items),
      end(this->Items),
      ostream_iterator<string>(cout, "\n")
    );
  }

  void printStackInReverse() const
  {
    // Reversed
    for (int i = sizeof(this->Items) / sizeof(this->Items[0]); i >= 0; i--) {
        cout << this->Items[i] << "\n";
    }
  }

  int getStackItemCount() const
  {
    return ItemSize;
  }

private:
  vector<string> Items;
  int ItemSize;
};

int main()
{
  Stack myStack;
  cout << myStack.isEmpty() << endl;
  myStack.setNewSize(0);
  myStack.insert("Alex");
  myStack.insert("Doug");
  myStack.printStack();
  myStack.printStackInReverse();
  myStack.pop();
  cout << "\n" << endl;
  cout << "SIZE OF MYSTACK IS: " << myStack.getStackItemCount() << endl;
  myStack.printStack();
  cout << myStack.contains("Alex") << endl;
  cout << myStack.contains("Doug") << endl;
  cout << myStack.peek() << endl;
  cout << myStack.isEmpty() << endl;
}
