#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE AdjacencyList testcases 1
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/test/execution_monitor.hpp>
#include "adjacency_list.h"

BOOST_AUTO_TEST_SUITE(suite1)

// Tests `add_vertex` and `has_vertex`
BOOST_AUTO_TEST_CASE(test1) {
  AdjacencyList<string, float> *adj_list = new AdjacencyList<string, float>();
  adj_list->add_vertex("A", 10.3, 9.4);
  BOOST_CHECK_EQUAL(adj_list->has_vertex("A"), 1);
  adj_list->~AdjacencyList();
};

BOOST_AUTO_TEST_SUITE_END();
