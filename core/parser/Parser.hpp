#ifndef REST_API_PARSER_HPP
#define REST_API_PARSER_HPP

#include <details/Item.hpp>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace rest_api::core {

    class Parser {
    public:
        Parser() = default;

        static std::pair<std::vector<Item>, std::vector<std::string>> parse(std::string string_items);
    private:
    };

}

#endif //REST_API_PARSER_HPP
