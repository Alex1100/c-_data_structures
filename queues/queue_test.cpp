#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Simple testcases 2
#include <boost/test/unit_test.hpp>
#include "queue.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(suite1)

// Tests `enqueue`
BOOST_AUTO_TEST_CASE(test1) {
  Queue<string> *myQueue = new Queue<string>(100);
  myQueue->enqueue("100");
  BOOST_CHECK_EQUAL(myQueue->get_front(), "100");
  myQueue->~Queue();
};

// Tests `contains`
BOOST_AUTO_TEST_CASE(test2) {
  Queue<int> *myQueue = new Queue<int>(100);
  myQueue->enqueue(99);
  BOOST_CHECK_EQUAL(myQueue->contains(99), 1);
  BOOST_CHECK_EQUAL(myQueue->contains(1000), 0);
  myQueue->~Queue();
};

BOOST_AUTO_TEST_SUITE_END();
