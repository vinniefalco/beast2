//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_HTTP_REQUEST_PARSER_HPP
#define BOOST_BEAST2_HTTP_REQUEST_PARSER_HPP

#include <boost/beast2/detail/config.hpp>
#include <boost/beast2/http/basic_parser.hpp>
#include <boost/beast2/error.hpp>
#include <cstddef>

namespace boost {
namespace beast2 {

struct request_header
{
};

struct chunk_header
{
};

enum class what
{
    none,
    header,
    body,
    chunk_header,
    chunk_body,
    chunk_final,
    end
};

class request_parser
    : public basic_parser
{
public:
#if 0
    /** Return the type of the current structured element.
    */
    beast2::what
    what() const noexcept;

    /** Return true if more input buffer data is needed.
    */
    bool
    need_more() const noexcept;

    /** Reserve space in the input buffer.
    */
    void
    reserve(std::size_t n);

    /** Attempt to advance the state of the parser to the next structured element.

        @return `false` if more data is needed.
    */
    bool
    next(error_code& ec);

    /** Return the request header.
    */
    request_header
    header();

    /** Return the chunk header.
    */
    chunk_header
    chunk_header();

    template<class Body>
    void
    attach_body();
#endif
};

#if 0
struct basic_body
{
    virtual void content_length(std::uint64_t n) = 0;
};

class string_body
{
    std::string s_;
    std::size_t n_ = 0;

public:
    void content_length(std::uint64_t n)
    {
        //if(n > std::string::max_size())
            // throw
        s_.resize(static_cast<
            std::size_t>(n));
        n_ = 0;
    }

    void write(net::const_buffer b)
    {
        n_ += net::buffer_copy(
            net::mutable_buffer(
                &s_[0] + n_,
                s_.size() - n_),
            b);
    }
};
#endif

} // beast2
} // boost

#endif
