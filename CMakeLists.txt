# global
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(telegram_test_bot)

set(vendorPath "${PROJECT_SOURCE_DIR}/vendor")

add_subdirectory(vendor)
add_subdirectory(app)
