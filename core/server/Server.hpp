#ifndef REST_API_SERVER_HPP
#define REST_API_SERVER_HPP

#include <details/Request.hpp>
#include <details/Response.hpp>
#include <handler/Handler.hpp>

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

    class Server {
    public:
        explicit Server(tcp::socket socket);

        void run();



    private:
        tcp::socket m_socket;
        beast::flat_buffer m_buffer{10000};
        http::request<http::dynamic_body> m_request;
        http::response<http::dynamic_body> m_response;

        Handler m_handler;

        void read_request();

        void process_request();
    };

}

#endif //REST_API_SERVER_HPP
