#include "Handler.hpp"

#include <sstream>

namespace rest_api::core {

    http::response<http::dynamic_body> Handler::handle_import_request(
            const http::request<http::dynamic_body>& request) {

        http::response<http::dynamic_body> res;
        std::string string_item = beast::buffers_to_string(request.body().data());
        auto [items, ids] = Parser::parse(string_item);

        if (!m_checker.is_ids_unique_in_request(ids)) {
            res.result(http::status::bad_request);
            beast::ostream(res.body()) << "Validation Failed";
            return res;
        }
        for (const Item& item : items) {
            if (!m_checker.check_import(item)) {
                res.result(http::status::bad_request);
                beast::ostream(res.body()) << "Validation Failed";
                return res;
            }
        }
    }
}