#ifndef REST_API_HANDLER_HPP
#define REST_API_HANDLER_HPP

#include <checker/Checker.hpp>
#include <parser/Parser.hpp>

#include <boost/beast.hpp>

#include <memory>
#include <utility>
#include <iostream>
#include <thread>

namespace beast = boost::beast;
namespace net = boost::asio;
namespace http = beast::http;

namespace rest_api::core {

    class Handler {
    public:
        Handler() = default;

        http::response<http::dynamic_body> handle_import_request(const http::request<http::dynamic_body>& request);


    private:
        Checker m_checker;
        Parser m_parser;
    };

}

#endif //REST_API_HANDLER_HPP
