set(
        SOURCES_CORE

        checker/Checker.hpp checker/Checker.cpp
        datebase/Database.hpp datebase/Database.cpp
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