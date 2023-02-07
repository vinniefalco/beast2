//
// Copyright (c) 2023 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/http_io
//

#ifndef BOOST_HTTP_IO_EXAMPLE_MUSTACHE_SOURCE_HPP
#define BOOST_HTTP_IO_EXAMPLE_MUSTACHE_SOURCE_HPP

#include <boost/buffers/buffer_copy.hpp>
#include <boost/buffers/source.hpp>
#include <boost/mustache/renderer.hpp>
#include <string>

class mustache_source
    : public boost::buffers::source
{
    boost::mustache::renderer mr_;
    std::string doc_;
    std::string out_;
    boost::buffers::const_buffer cb_;

public:
    explicit
    mustache_source(
        std::string doc,
        boost::json::object table)
        : doc_(std::move(doc))
        , mr_(table, boost::json::object{})
    {
        boost::mustache::output_ref out(out_);
        mr_.render_some(doc_, out);
        mr_.finish(out);
        cb_ = { out_.data(), out_.size() };
    }

    results
    do_read_one(
        void* dest,
        std::size_t size) override
    {
        results rv;
        rv.bytes =
            boost::buffers::buffer_copy(
                boost::buffers::mutable_buffer(
                    dest, size),
                cb_);
        cb_ += rv.bytes;
        rv.finished = cb_.size() == 0;
        return rv;
    }
};

#endif
