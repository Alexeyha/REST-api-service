#ifndef REST_API_REQUEST_HPP
#define REST_API_REQUEST_HPP

#include <boost/beast.hpp>

#include <memory>
#include <utility>
#include <iostream>
#include <thread>

namespace beast = boost::beast;
namespace net = boost::asio;
namespace http = beast::http;

using tcp = boost::asio::ip::tcp;

namespace rest_api::core {

    class Request {
    public:

    private:
        http::request<http::dynamic_body> request_;
    };

}

#endif //REST_API_REQUEST_HPP
