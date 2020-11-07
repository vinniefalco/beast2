//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_HTTP_REQUEST_VIEW_HPP
#define BOOST_BEAST2_HTTP_REQUEST_VIEW_HPP

#include <cstdlib>

namespace boost {
namespace beast2 {

class request_view
{
    char const* s_;
    std::size_t n_;

public:
};

} // boost
} // beast2

#endif
