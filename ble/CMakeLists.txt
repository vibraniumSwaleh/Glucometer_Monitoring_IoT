# Standalone example that reads from the on board temperature sensor and sends notifications via BLE
# Flashes slowly each second to show it's running
cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_SDK_PATH "/home/ghost/pico/pico-sdk")
set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(gatt_temp_server C CXX ASM)
pico_sdk_init()

add_executable(gatt_temp_server
    server.c server_common.c
    )
target_link_libraries(gatt_temp_server
    pico_stdlib
    pico_btstack_ble
    pico_btstack_cyw43
    pico_cyw43_arch_none
    hardware_adc
    )
target_include_directories(gatt_temp_server PRIVATE
    ${CMAKE_CURRENT_LIST_DIR} # For btstack config
    )

# pico_btstack_make_gatt_header(gatt_temp_server PRIVATE "${CMAKE_CURRENT_LIST_DIR}/temp_sensor.gatt")

pico_add_extra_outputs(gatt_temp_server)


