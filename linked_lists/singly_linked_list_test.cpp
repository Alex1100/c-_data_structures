#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Singly_Linked_List testcases 5
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/test/execution_monitor.hpp>
#include "singly_linked_list.h"

BOOST_AUTO_TEST_SUITE(suite1)

// Tests `add_node`
BOOST_AUTO_TEST_CASE(test1) {
  LinkedList<string> *ll = new LinkedList<string>();
  ll->add_node("100");
  BOOST_CHECK_EQUAL(ll->get_head()->data, "100");
  ll->~LinkedList();
};

// Tests `contains`
BOOST_AUTO_TEST_CASE(test2) {
  LinkedList<int> *ll = new LinkedList<int>();
  ll->add_node(90);
  BOOST_CHECK_EQUAL(ll->contains(87), false);
  BOOST_CHECK_EQUAL(ll->contains(90), true);
  ll->~LinkedList();
};

// Tests `get_head`
BOOST_AUTO_TEST_CASE(test3) {
  LinkedList<int> *ll = new LinkedList<int>();
  ll->add_node(90);
  BOOST_CHECK_NO_THROW(assert(ll->get_head()));
  ll->~LinkedList();
}

// Tests `get_tail`
BOOST_AUTO_TEST_CASE(test4) {
  LinkedList<int> *ll = new LinkedList<int>();
  ll->add_node(90);
  BOOST_CHECK_NO_THROW(assert(ll->get_tail()));
  ll->~LinkedList();
}

// Tests `remove_node`
BOOST_AUTO_TEST_CASE(test5) {
  LinkedList<int> *ll = new LinkedList<int>();
  BOOST_REQUIRE_THROW(assert(ll->remove_node(10)), runtime_error);
  ll->add_node(90);
  ll->add_node(20);

  BOOST_CHECK_NO_THROW(assert(ll->remove_node(20)));
  BOOST_CHECK_EQUAL(ll->contains(20), false);
  BOOST_CHECK_EQUAL(ll->contains(90), true);
  ll->remove_node(90);
  BOOST_CHECK_EQUAL(ll->contains(90), false);
  ll->~LinkedList();
}

BOOST_AUTO_TEST_SUITE_END();
