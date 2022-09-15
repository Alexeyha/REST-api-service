#include "core/checker/Checker.hpp"
#include "core/database/Database.hpp"
#include "core/handler/Handler.hpp"

#include <boost/beast.hpp>

#include <memory>
#include <utility>
#include <iostream>
#include <thread>

namespace beast = boost::beast;
namespace net = boost::asio;

using tcp = boost::asio::ip::tcp;

namespace rest_api::service {



}

int main() {
    net::io_context io_context;
    net::ip::address address = net::ip::make_address("0.0.0.0");
    uint8_t port = 80;

    tcp::acceptor acceptor(
            io_context,
            tcp::endpoint(address, port)
    );

    std::cout << "Hi from me.";


}
