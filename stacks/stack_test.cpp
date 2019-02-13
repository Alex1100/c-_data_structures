#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Simple testcases 2
#include <boost/test/unit_test.hpp>
#include "stack.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(suite1)

// Tests `insert`
BOOST_AUTO_TEST_CASE(test1) {
  Stack<int> *myStack = new Stack<int>(100);
  myStack->insert(99);
  BOOST_CHECK_EQUAL(myStack->getItemAt(0), 99);
  myStack->~Stack();
}

// Tests `contains`
BOOST_AUTO_TEST_CASE(test2) {
  Stack<string> *myStack = new Stack<string>(10);
  myStack->insert("1");
  myStack->insert("2");
  myStack->insert("3");
  string topOfStack = {myStack->pop()};
  BOOST_CHECK_EQUAL(topOfStack, "3");
  BOOST_CHECK_EQUAL(myStack->get_count_of_items(), 2);
  myStack->~Stack();
}

BOOST_AUTO_TEST_SUITE_END()
