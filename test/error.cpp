//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

// Test that header file is self-contained.
#include <boost/beast2/error.hpp>

#include "test_suite.hpp"

namespace boost {
namespace beast {

class error_test
{
public:
    void run()
    {
        // library-wide errors go here
    }
};

TEST_SUITE(error_test, "boost.beast2.error");

} // beast2
} // boost
