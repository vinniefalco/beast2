//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_HTTP_STRING_READER_HPP
#define BOOST_BEAST2_HTTP_STRING_READER_HPP

#include <boost/beast2/error.hpp>
#include <cstdlib>
#include <string>

namespace boost {
namespace beast2 {

class string_reader
{
    std::string s_;

public:
    void
    reserve(
        std::size_t size);

    void
    write(
        void const* data,
        std::size_t size,
        error_code& ec);
};

} // boost
} // beast2

#endif
