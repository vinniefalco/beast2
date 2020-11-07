//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_HTTP_BASIC_PARSER_HPP
#define BOOST_BEAST2_HTTP_BASIC_PARSER_HPP

#include <boost/beast2/detail/config.hpp>
#include <boost/beast2/buffers.hpp>
#include <boost/beast2/error.hpp>
#include <cstddef>

namespace boost {
namespace beast2 {

class basic_parser
{
    char* data_;
    std::size_t cap_;
    net::mutable_buffer b_;

public:
    ~basic_parser();

    basic_parser() noexcept;

    bool
    need_more() const noexcept;

    mutable_buffers
    prepare();

    void
    commit(std::size_t n);
};

} // beast2
} // boost

#endif
