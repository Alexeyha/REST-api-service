#include <core/checker/Checker.hpp>
#include <core/database/Database.hpp>
#include <core/handler/Handler.hpp>
#include <core/server/Server.hpp>

#include <boost/beast.hpp>

#include <memory>
#include <utility>
#include <iostream>
#include <thread>

namespace beast = boost::beast;
namespace net = boost::asio;
namespace http = beast::http;

using tcp = boost::asio::ip::tcp;

namespace rest_api::service {

    void run_server(tcp::acceptor &acceptor, tcp::socket &socket) {
        acceptor.async_accept(socket, [&](beast::error_code ec) {
            if (!ec) {
                std::make_shared<rest_api::core::Server>(std::move(socket))->run();
            }
            run_server(acceptor, socket);
        });
    }

} //namespace rest_api::service

int main() {
    net::io_context io_context;
    net::ip::address address = net::ip::make_address("0.0.0.0");
    uint8_t port = 80;

    tcp::acceptor acceptor(
            io_context,
            tcp::endpoint(address, port)
    );
    io_context.run();

}
