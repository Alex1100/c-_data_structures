#include <iostream>
#include <vector>
using namespace std;

class Queue
{
public:
  void enqueue(string item)
  {
    this->Items.push_back(item);
    setQueueSize(this->QueueSize + 1);
  }

  string dequeue()
  {
    string removed = this->Items[0];
    this->Items.erase(this->Items.begin(), this->Items.begin() + 1);
    return removed;
  }

  string front() const
  {
    return this->Items[0];
  }

  string back() const
  {
    return this->Items[this->QueueSize - 1];
  }

  bool contains(string item) const
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
      ostream_iterator<string>(cout, "\n")
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
  vector<string> Items;
  int QueueSize;
};

int main()
{
  Queue myQueue;
  myQueue.setQueueSize(0);
  myQueue.enqueue("Alex");
  myQueue.enqueue("Doug");
  myQueue.enqueue("Finance");
  myQueue.printQueue();
  myQueue.dequeue();
  cout << "\n" << endl;
  cout << "SIZE OF MY QUEUE IS: " << myQueue.getQueueSize() << endl;
  myQueue.printQueue();
  cout << myQueue.contains("Alex") << endl;
  cout << myQueue.contains("Doug") << endl;
  cout << myQueue.front() << endl;
  cout << myQueue.isEmpty() << endl;
}
