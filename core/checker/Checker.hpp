#ifndef REST_API_CHECKER_HPP
#define REST_API_CHECKER_HPP

#include "database/Database.hpp"

#include <algorithm>
#include <string>
#include <regex>
#include <set>

namespace rest_api::core {

    class Checker {
    public:
        [[nodiscard]] bool is_date_format_correct(const std::string &date) const noexcept;

        [[nodiscard]] static bool is_id_unique(const std::string &id,
                                        const std::shared_ptr<Database> &database) noexcept;

        [[nodiscard]] static std::string is_id_correct(const std::string &id,
                                         const std::shared_ptr<Database> &database) noexcept;

        [[nodiscard]] static bool is_ids_unique_in_request(const std::vector<std::string> &ids) noexcept;

    private:
        std::string m_regex_date = "^(?:[1-9]\\d{3}-(?:(?:0[1-9]|1[0-2])-(?:0[1-9]|1\\d|2[0-8])|"
                                   "(?:0[13-9]|1[0-2])-(?:29|30)|(?:0[13578]|1[02])-31)|(?:[1-9]\\"
                                   "d(?:0[48]|[2468][048]|[13579][26])|(?:[2468][048]|[13579][26])"
                                   "00)-02-29)T(?:[01]\\d|2[0-3]):[0-5]\\d:[0-5]\\d(?:Z|[+-][01]\\"
                                   "d:[0-5]\\d)";

    };

}

#endif //REST_API_CHECKER_HPP
