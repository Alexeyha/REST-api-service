#include <boost/beast.hpp>

#include <memory>
#include <utility>

namespace beast = boost::beast;
namespace net = boost::asio;

using tcp = boost::asio::ip::tcp;

int main() {
    net::io_context io_context;
    net::ip::address address = net::ip::make_address("0.0.0.0");
    uint8_t port = 80;

    tcp::acceptor acceptor(
            io_context,
            tcp::endpoint(address, port)
    );
}
