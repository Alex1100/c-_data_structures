#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Stack testcases 5
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/test/execution_monitor.hpp>
#include "stack.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(suite1)

// Tests `insert`
BOOST_AUTO_TEST_CASE(test1) {
  Stack<int> *ss = new Stack<int>(1);
  ss->insert(99);
  BOOST_CHECK_EQUAL(ss->get_item_at(0), 99);
  BOOST_CHECK_THROW(assert(ss->insert(10)), runtime_error);
  ss->~Stack();
}

// Tests `pop`
BOOST_AUTO_TEST_CASE(suite2) {
  Stack<string> *ss = new Stack<string>(10);
  ss->insert("1");
  ss->insert("2");
  ss->insert("3");
  string topOfStack = {ss->pop()};
  BOOST_CHECK_EQUAL(topOfStack, "3");
  ss->pop();
  ss->pop();
  BOOST_CHECK_THROW(ss->pop(), runtime_error);
  ss->~Stack();
}

// Tests `get_item_at`
BOOST_AUTO_TEST_CASE(suite3) {
  Stack<string> *ss = new Stack<string>(40);
  ss->insert("1");
  ss->insert("2");
  ss->insert("3");
  BOOST_CHECK_EQUAL(ss->get_item_at(0), "3");
  BOOST_CHECK_THROW(ss->get_item_at(55), runtime_error);
  BOOST_CHECK_THROW(ss->get_item_at(39), runtime_error);
  ss->pop();
  ss->pop();
  ss->pop();
  BOOST_CHECK_THROW(ss->get_item_at(0), runtime_error);
  ss->~Stack();
}

// Tests `is_empty`
BOOST_AUTO_TEST_CASE(suite4) {
  Stack<string> *ss = new Stack<string>(10);
  ss->insert("1");
  ss->insert("2");
  ss->insert("3");
  ss->pop();
  BOOST_CHECK_EQUAL(ss->is_empty(), false);
  ss->pop();
  ss->pop();
  BOOST_CHECK_EQUAL(ss->is_empty(), true);
  ss->~Stack();
}

// Tests `get_count_of_items`
BOOST_AUTO_TEST_CASE(test5) {
  Stack<string> *ss = new Stack<string>(10);
  ss->insert("1");
  ss->insert("2");
  ss->insert("3");
  BOOST_CHECK_EQUAL(ss->get_count_of_items(), 3);
  ss->~Stack();
}

BOOST_AUTO_TEST_SUITE_END()
