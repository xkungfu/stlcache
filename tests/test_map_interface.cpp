//
// Copyright (C) 2011-2019 Denis V Chapligin
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#define BOOST_TEST_MODULE "STLCacheMapInterface"
#include <boost/test/unit_test.hpp>

#include <stlcache/stlcache.hpp>

using namespace stlcache;

BOOST_AUTO_TEST_SUITE(STLCacheSuite)

BOOST_AUTO_TEST_CASE(at) {
  cache<int,string,policy_none> c(10);

  BOOST_CHECK(c.empty());

  BOOST_CHECK(c.insert(1,string("test"))); //Insert returns true for new entries

  BOOST_CHECK(!c.at(1).compare("test"));
  BOOST_REQUIRE_THROW(c.at(2),std::out_of_range);

  const std::string& value = c.at(1);
  BOOST_CHECK(!value.compare("test"));
}

BOOST_AUTO_TEST_CASE(brackets) {
  cache<int,string,policy_lfu> c(3);

  c.insert(1,"data1");
  c.insert(2,"data2");
  BOOST_CHECK(!c[2].compare("data2"));

  BOOST_CHECK(!c[3].compare("")); //This one sets
  BOOST_CHECK(!c[3].compare("")); //And this one retrieves back

  BOOST_CHECK(!c[4].compare(""));

  BOOST_CHECK(c.size()==3);
}

BOOST_AUTO_TEST_SUITE_END()