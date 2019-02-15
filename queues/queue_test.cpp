#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Queue testcases 6
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/test/execution_monitor.hpp>
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

// Tests `get_item_at`
BOOST_AUTO_TEST_CASE(test3) {
  Queue<int> *myQueue = new Queue<int>(100);
  myQueue->enqueue(99);
  BOOST_CHECK_EQUAL(myQueue->get_item_at(0), 99);
  BOOST_WARN_THROW(assert(myQueue->get_item_at(1)), runtime_error);
  myQueue->~Queue();
}

// Tests `is_empty`
BOOST_AUTO_TEST_CASE(test4) {
  Queue<int> *myQueue = new Queue<int>(100);
  Queue<string> *qq = new Queue<string>(10);
  myQueue->enqueue(99);
  BOOST_CHECK_EQUAL(myQueue->is_empty(), false);
  BOOST_CHECK_EQUAL(qq->is_empty(), true);
  myQueue->~Queue();
  qq->~Queue();
}

// Tests `get_front`
BOOST_AUTO_TEST_CASE(test5) {
  Queue<int> *qq = new Queue<int>(10);
  BOOST_REQUIRE_THROW(assert(qq->get_front()), runtime_error);
  qq->enqueue(90);
  BOOST_CHECK_NO_THROW(assert(qq->get_front()));
  qq->~Queue();
}

// Tests `dequeue`
BOOST_AUTO_TEST_CASE(test6) {
  Queue<int> *qq = new Queue<int>(10);
  BOOST_REQUIRE_THROW(assert(qq->dequeue()), runtime_error);
  qq->enqueue(90);
  qq->enqueue(20);

  BOOST_CHECK_NO_THROW(assert(qq->dequeue()));
  BOOST_CHECK_EQUAL(qq->contains(90), false);
  BOOST_CHECK_EQUAL(qq->contains(20), true);
  qq->dequeue();
  BOOST_CHECK_EQUAL(qq->contains(20), false);
  qq->~Queue();
}

BOOST_AUTO_TEST_SUITE_END();
