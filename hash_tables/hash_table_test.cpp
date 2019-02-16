#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hash_Table testcases 1
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/test/execution_monitor.hpp>
#include "hash_table.h"

BOOST_AUTO_TEST_SUITE(suite1)

// Tests `get_size`
BOOST_AUTO_TEST_CASE(test1) {
  HashTable<string, int> *ht = new HashTable<string, int>(10);
  ht->insert("100", 20);
  BOOST_CHECK_EQUAL(ht->get_size(), 1);
  ht->~HashTable();
};

BOOST_AUTO_TEST_SUITE_END();
