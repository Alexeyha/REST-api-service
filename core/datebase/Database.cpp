#include "Database.hpp"

namespace rest_api::core {

    Database::Database() : m_conn("dbname = rest_api") {

    }

}