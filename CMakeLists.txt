cmake_minimum_required(VERSION 3.19)
project(rest-api)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# JSON parce library
set(DIRECTORY_JSON ${PROJECT_SOURCE_DIR}/deps/json)
set(INCLUDE_JSON ${DIRECTORY_JSON}/include)

message(STATUS "JSON include: ${INCLUDE_JSON}")


# libpqxx library
set(DIRECTORY_LIBPQXX ${PROJECT_SOURCE_DIR}/deps/libpqxx)
set(INCLUDE_LIBPQXX ${DIRECTORY_LIBPQXX}/include)

message(STATUS "LIBPQXX include: ${INCLUDE_LIBPQXX}")


# Boost library
find_package(Boost 1.71 REQUIRED filesystem)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

target_link_libraries(${Boost_LIBRARIES})


# Core library
set(DIRECTORY_CORE ${PROJECT_SOURCE_DIR}/core)
set(INCLUDE_CORE ${DIRECTORY_CORE})
set(LIBRARY_CORE engine)

add_subdirectory(${DIRECTORY_CORE})
message(STATUS "Core include: ${INCLUDE_CORE}")
message(STATUS "Core library: ${LIBRARY_CORE}")


# Service
set(DIRECTORY_SERVICE ${PROJECT_SOURCE_DIR}/service)
set(EXECUTABLE_SERVICE example)

add_subdirectory(${DIRECTORY_SERVICE})
message(STATUS "Service executable: ${EXECUTABLE_SERVICE}")