function(service_executable EXECUTABLE_SERVICE_NAME EXECUTABLE_SOURCES)
    message(STATUS "Service executable: '${EXECUTABLE_SERVICE_NAME}' is built with ${EXECUTABLE_SOURCES}")

    add_executable(
            ${EXECUTABLE_SERVICE_NAME}
            ${EXECUTABLE_SOURCES}
    )

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        target_compile_definitions(${EXECUTABLE_SERVICE_NAME} PUBLIC SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE)
        message(STATUS "Enable debug logs for ${EXECUTABLE_SERVICE_NAME}")
    endif()

    target_include_directories(
            ${EXECUTABLE_SERVICE_NAME} PUBLIC

            ${PROJECT_SOURCE_DIR}
            ${INCLUDE_JSON}
    )

    target_link_libraries(
            ${EXECUTABLE_SERVICE_NAME}

            ${LIBRARY_CORE}
            ${LIBRARY_JSON}
            ${LIBRARY_LIBPQXX}
            ${Boost_LIBRARIES}
    )

endfunction()

add_compile_options(-lpthread)
service_executable(${EXECUTABLE_SERVICE} service.cpp)
