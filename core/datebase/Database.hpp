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



    private:
        pqxx::connection m_conn;
        std::string m_request;

    };

}

#endif //REST_API_DATABASE_HPP
