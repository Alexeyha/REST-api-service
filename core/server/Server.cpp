#include "Server.hpp"

#include <handler/Handler.hpp>

namespace rest_api::core {


    Server::Server(tcp::socket socket) : m_socket(std::move(socket)) {

    }

    void Server::run() {
        read_request();
    }

    void Server::read_request() {
        http::async_read(
                m_socket,
                m_buffer,
                m_request,
                [&](beast::error_code error_code, std::size_t bytes_transferred) {
                    boost::ignore_unused(bytes_transferred);
                    if (!error_code)
                        process_request();
                });
    }

    void Server::process_request() {
        switch (m_request.method()) {
            case http::verb::post:
                m_handler.handle_import_request(m_request);
                m_response.result(http::status::ok);

//                create_response();
                break;

            default:
                m_response.result(http::status::bad_request);
                m_response.set(http::field::content_type, "text/plain");
                beast::ostream(m_response.body())
                        << "Invalid request-method '"
                        << std::string(m_request.method_string())
                        << "'";
                break;
        }
    }

}