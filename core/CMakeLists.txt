set(
        SOURCES_CORE

        checker/Checker.hpp checker/Checker.cpp
        database/Database.hpp database/Database.cpp
        details/Item.hpp
        handler/Handler.hpp handler/Handler.cpp
        parser/Parser.hpp parser/Parser.cpp
        server/Server.hpp server/Server.cpp

)

add_library(
        ${LIBRARY_CORE} STATIC

        ${SOURCES_CORE}
)

target_include_directories(
        ${LIBRARY_CORE} PUBLIC

        ${INCLUDE_CORE}
        ${INCLUDE_JSON}
        ${INCLUDE_LIBPQXX}
)

target_link_libraries(
        ${LIBRARY_CORE}

        ${LIBRARY_JSON}
        ${LIBRARY_LIBPQXX}
        ${Boost_LIBRARIES}
)