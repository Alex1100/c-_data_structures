#include "adjacency_list.h"


int main(void) {
  AdjacencyList<string, float> *adj_list = new AdjacencyList<string, float>();

  adj_list->add_vertex("A", 10.3, 13.5);
  adj_list->add_vertex("B", 4.9, 10.5);
  adj_list->add_vertex("C", 9.4, 5.4);
  adj_list->add_vertex("D", 3.4, 1.2);
  adj_list->add_vertex("E", 11.5, 34.2);
  adj_list->add_vertex("F", 95.2, 14.8);
  adj_list->add_vertex("G", 1.3, 55.3);
  adj_list->add_vertex("H", 10.6, 13.8);
  cout << adj_list->has_vertex("A") << "\n" << endl;

  adj_list->add_edges("A", "B");
  adj_list->add_edges("A", "C");
  adj_list->add_edges("A", "D");
  adj_list->add_edges("C", "G");
  adj_list->add_edges("G", "H");
  adj_list->add_edges("D", "H");
  adj_list->add_edges("H", "F");
  adj_list->add_edges("B", "E");
  adj_list->add_edges("E", "H");
  adj_list->add_edges("F", "B");

  Stack<string> *dfs_result = adj_list->depth_first_search("A");
  int total_items_count = dfs_result->get_count_of_items();

  cout << "__DEPTH FIRST SEARCH__\n" << endl;

  for (int i = 0; i < total_items_count; i++) {
    cout << dfs_result->pop() << endl;
  }

  return 0;
}
