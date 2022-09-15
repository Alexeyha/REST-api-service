#include "Database.hpp"

namespace rest_api::core {

    Database::Database() : m_conn("dbname = rest_api") {
        m_request = "CREATE TABLE IF NOT EXISTS items("
                    "id text,"
                    "url text,"
                    "parentId text,"
                    "size int,"
                    "type text,"
                    "updateDate text);";

        pqxx::work session(m_conn);
        session.exec(m_request);


    }

    bool Database::is_id_exist(const std::string &id) noexcept {
        m_request = "select exists (select * from items where id = '" + id + "');";

        pqxx::work session(m_conn);

        return session.query_value<std::string>(m_request) == "t";
    }

    void Database::import(const std::string &id, const std::string &url, const std::string &parent_id, int size,
                          const std::string &type, const std::string &update_date) noexcept {
        m_request = "insert into items values ('"
                    + id + "', '" + url + "', '" + "', '"
                    + parent_id + "', " + std::to_string(size)
                    + ", '" + type + "', '" + update_date + "');";

        pqxx::work session(m_conn);
        session.exec(m_request);
    }

    std::string Database::get_parent_id(const std::string &id) {
        m_request = "select parentId from items where id = '" + id + "';";

        pqxx::work session(m_conn);

        return session.query_value<std::string>(m_request);
    }

    std::string Database::get_type(const std::string &id) {
        if (!is_id_exist(id)) {
            return "null";
        }
        m_request = "select type from items where id = '" + id + "';";

        pqxx::work session(m_conn);

        return session.query_value<std::string>(m_request);
    }


}