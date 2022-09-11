cmake_minimum_required(VERSION 3.19)
project(mad)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# JSON parce library
set(DIRECTORY_JSON ${PROJECT_SOURCE_DIR}/deps/json)
set(INCLUDE_JSON ${DIRECTORY_JSON}/include)

message(STATUS "JSON include: ${INCLUDE_JSON}")


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