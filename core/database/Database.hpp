#ifndef REST_API_DATABASE_HPP
#define REST_API_DATABASE_HPP

#include <string>

#include <pqxx/pqxx>
#include <nlohmann/json.hpp>
#include <boost/beast.hpp>

using json = nlohmann::json;
namespace http = boost::beast::http;

namespace rest_api::core {

    class Database {
    public:
        Database();

        void import(const std::string &id, const std::string &url,
                    const std::string &parent_id, int size,
                    const std::string &type, const std::string &update_date) noexcept;

        [[nodiscard]] bool is_id_exist(const std::string &id) noexcept;

        std::string get_parent_id(const std::string &id);

        [[nodiscard]] std::string get_type(const std::string &id);

    private:
        pqxx::connection m_conn;
        std::string m_request;

    };

}

#endif //REST_API_DATABASE_HPP
