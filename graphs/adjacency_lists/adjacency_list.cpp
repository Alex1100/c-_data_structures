#include "adjacency_list.h"


int main(void) {
  AdjacencyList<int> *adjList = new AdjacencyList<int>();
  adjList->add_vertex("A");
  cout << adjList->has_vertex("A") << endl;
  adjList->add_vertex("C");
  adjList->add_vertex("B");
  adjList->add_vertex("F");
  adjList->add_vertex("E");
  adjList->add_vertex("D");


  adjList
  return 0;
}
