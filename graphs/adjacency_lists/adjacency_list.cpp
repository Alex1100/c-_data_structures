#include "adjacency_list.h"


int main(void) {
  AdjacencyList<string, float> *adj_list = new AdjacencyList<string, float>();
  adj_list->add_vertex("A", 10.3, 13.5);
  cout << adj_list->has_vertex("A") << endl;
  adj_list->add_vertex("C", 9.4, 5.4);
  adj_list->add_vertex("B", 4.9, 10.5);
  adj_list->add_vertex("F", 3.4, 1.2);
  adj_list->add_vertex("E", 11.5, 34.2);
  adj_list->add_vertex("D", 95.2, 14.8);

  adj_list->add_edges("A", "E");
  adj_list->add_edges("E", "C");
  adj_list->add_edge("C", "F");
  adj_list->add_edges("F", "A");
  adj_list->add_edge("A", "D");
  return 0;
}
