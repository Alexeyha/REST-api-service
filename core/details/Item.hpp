#ifndef REST_API_ITEM_HPP
#define REST_API_ITEM_HPP

#include <string>
#include <utility>

namespace rest_api::core {

    struct Item {
        Item(std::string id, std::string url, std::string parent_id,
             int size, std::string type, std::string time) : id(std::move(id)),
             url(std::move(url)), parent_id(std::move(parent_id)),
             size(size), type(std::move(type)), time(std::move(time)) {
        }

        std::string id;
        std::string url;
        std::string parent_id;
        int size;
        std::string type;
        std::string time;
    };

}

#endif //REST_API_ITEM_HPP
