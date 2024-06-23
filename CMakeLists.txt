# boilerplate cmake
cmake_minimum_required(VERSION 3.20.0)

# import custom board package
list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/)
# list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/boards/freenove/espressif/esp_)


# import zephyr package; this is required for ZephyrOS cmake system to work
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

file(GLOB_RECURSE srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*)

target_sources(app PRIVATE ${srcs})
