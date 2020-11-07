//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_BUFFER_HPP
#define BOOST_BEAST2_BUFFER_HPP

#include <boost/beast2/detail/config.hpp>
#include <boost/asio/buffer.hpp>

namespace boost {
namespace beast2 {

using const_buffer = boost::asio::const_buffer;
using mutable_buffer = boost::asio::mutable_buffer;

} // beast2
} // boost

#endif
