#include "Parser.hpp"

namespace rest_api::core {

    std::pair<std::vector<Item>, std::vector<std::string>> Parser::parse(std::string string_items) {
        json json_items(string_items);
        std::string time = json_items["updateDate"];
        std::vector<Item> items;
        std::vector<std::string> items_ids;
        for (json item : json_items["items"]) {
            items.emplace_back(item["id"], item["url"], item["parentId"],
                             item["size"], item["type"], time);
            items_ids.push_back(item["id"]);
        }

    }
}