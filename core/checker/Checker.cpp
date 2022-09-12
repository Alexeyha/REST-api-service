#include "Checker.hpp"

namespace rest_api::core {


    bool Checker::is_date_format_correct(const std::string &date) const noexcept {
        std::regex regex_date(m_regex_date);

        return std::regex_match(date, regex_date);
    }

    bool Checker::is_id_unique(const std::string &id,
                               const std::shared_ptr<Database> &database) noexcept {
        return !database->is_id_exist(id);
    }

    std::string Checker::is_id_correct(const std::string &id, const std::shared_ptr<Database> &database) noexcept {
        if (id == "null") {
            return "null";
        }
        if (!is_id_unique(id, database)) {
            return "update";
        }
        return "unique";
    }

    bool Checker::is_ids_unique_in_request(const std::vector<std::string> &ids) noexcept {
        std::set ids_set(ids.begin(), ids.end());
        return ids.size() == ids_set.size();
    }


}