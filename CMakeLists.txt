cmake_minimum_required(VERSION 3.16)
project(rest-api)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

SET(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
SET(GCC_COVERAGE_LINK_FLAGS    "-lpthread")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# JSON parce library
set(DIRECTORY_JSON ${PROJECT_SOURCE_DIR}/deps/json)
set(INCLUDE_JSON ${DIRECTORY_JSON}/include)

message(STATUS "JSON include: ${INCLUDE_JSON}")


# libpqxx library
set(DIRECTORY_LIBPQXX ${PROJECT_SOURCE_DIR}/deps/libpqxx)
set(INCLUDE_LIBPQXX ${DIRECTORY_LIBPQXX}/include)
set(LIBRARY_LIBPQXX pqxx)

add_subdirectory(${DIRECTORY_LIBPQXX})

message(STATUS "LIBPQXX include: ${INCLUDE_LIBPQXX}")


# Boost library
find_package(Boost 1.7 REQUIRED filesystem)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


# Core library
set(DIRECTORY_CORE ${PROJECT_SOURCE_DIR}/core)
set(INCLUDE_CORE ${DIRECTORY_CORE})
set(LIBRARY_CORE engine)

add_subdirectory(${DIRECTORY_CORE})
message(STATUS "Core include: ${INCLUDE_CORE}")
message(STATUS "Core library: ${LIBRARY_CORE}")


# Service
set(DIRECTORY_SERVICE ${PROJECT_SOURCE_DIR}/service)
set(EXECUTABLE_SERVICE service)

add_subdirectory(${DIRECTORY_SERVICE})
message(STATUS "Service executable: ${EXECUTABLE_SERVICE}")
