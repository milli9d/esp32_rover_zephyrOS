# boilerplate cmake
cmake_minimum_required(VERSION 3.20.0)

# import custom board package
list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../)

# import overlays for CPUs
# if(DEFINED BOARD_ESP32_ROVER_PROCPU)
#     set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/applications/app_core/esp32_rover_robocar_procpu.overlay)
# elseif(DEFINED BOARD_ESP32_ROVER_APPCPU)
    set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/esp32_rover_robocar_appcpu.overlay)
# endif()

# import zephyr package; this is required for ZephyrOS cmake system to work
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ESP32_ROVER_APPCPU)

file(GLOB_RECURSE srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*)

target_sources(app PRIVATE ${srcs})
