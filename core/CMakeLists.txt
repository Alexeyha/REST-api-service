set(
        SOURCES_CORE

)

add_library(
        ${LIBRARY_CORE} STATIC

        ${SOURCES_CORE}
)

target_include_directories(
        ${LIBRARY_CORE} PUBLIC

        ${INCLUDE_CORE}
        ${INCLUDE_JSON}
)

target_link_libraries(
        ${LIBRARY_CORE}

        ${LIBRARY_JSON}
)