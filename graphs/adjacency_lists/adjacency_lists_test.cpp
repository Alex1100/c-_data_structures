#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE AdjacencyList testcases 4
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/test/execution_monitor.hpp>
#include "adjacency_list.h"

BOOST_AUTO_TEST_SUITE(suite1)

// Tests `add_vertex` and `has_vertex`
BOOST_AUTO_TEST_CASE(test1) {
  AdjacencyList<string, float> *adj_list = new AdjacencyList<string, float>();
  adj_list->add_vertex("A", 10.3, 9.4);
  BOOST_CHECK_EQUAL(adj_list->has_vertex("A"), true);
  adj_list->~AdjacencyList();
}

// Tests `add_edges` and `has_edges`
BOOST_AUTO_TEST_CASE(test2) {
  AdjacencyList<string, float> *adj_list = new AdjacencyList<string, float>();
  adj_list->add_vertex("A", 10.3, 9.4);
  adj_list->add_vertex("X", 0.3, 2.4);
  adj_list->add_edges("X", "A");
  BOOST_CHECK_EQUAL(adj_list->has_edges("X", "A"), true);
  adj_list->~AdjacencyList();
}

// Tests `add_edge` and `has_edge`
BOOST_AUTO_TEST_CASE(test3) {
  AdjacencyList<string, float> *adj_list = new AdjacencyList<string, float>();
  adj_list->add_vertex("A", 10.3, 9.4);
  adj_list->add_vertex("X", 0.3, 2.4);
  adj_list->add_edge("X", "A");
  BOOST_CHECK_EQUAL(adj_list->has_edge("X", "A"), true);
  adj_list->~AdjacencyList();
}

// Tests `depth_first_search`
BOOST_AUTO_TEST_CASE(test4) {
  AdjacencyList<string, float> *adj_list = new AdjacencyList<string, float>();

  adj_list->add_vertex("A", 10.3, 13.5);
  adj_list->add_vertex("B", 4.9, 10.5);
  adj_list->add_vertex("C", 9.4, 5.4);
  adj_list->add_vertex("D", 3.4, 1.2);
  adj_list->add_vertex("E", 11.5, 34.2);
  adj_list->add_vertex("F", 95.2, 14.8);
  adj_list->add_vertex("G", 1.3, 55.3);
  adj_list->add_vertex("H", 10.6, 13.8);
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

  string result[8] = { "E", "D", "H", "C", "G", "B", "F", "A" };

  for (int i = 0; i < total_items_count; i++) {
    BOOST_CHECK_EQUAL(dfs_result->pop(), result[i]);
  }

  adj_list->~AdjacencyList();
}

BOOST_AUTO_TEST_SUITE_END();
